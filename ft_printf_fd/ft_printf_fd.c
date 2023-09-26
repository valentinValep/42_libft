/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 15:28:20 by vlepille          #+#    #+#             */
/*   Updated: 2023/09/26 16:59:57 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "ft_printf_fd.h"

static void	ft_fun_conv_fd(char c, va_list *args, t_display_buffer_fd *buf, int fd)
{
	int					i;
	const char			format_list[CONVERSION_NUMBER] = "cspdiuxX%";
	t_fun_conv_fd const	fun_list[CONVERSION_NUMBER] = {&ft_char_conv_fd,
		&ft_string_conv_fd, &ft_pointer_conv_fd, &ft_decimal_conv_fd, &ft_integer_conv_fd,
		&ft_unsigned_conv_fd, &ft_lower_hexa_conv_fd, &ft_upper_hexa_conv_fd,
		&ft_percent_conv_fd};

	i = -1;
	while (++i < CONVERSION_NUMBER && format_list[i] != c)
		;
	if (i == CONVERSION_NUMBER)
	{
		ft_write_buf_fd(fd, buf, (char []){'%', c}, 2);
		return ;
	}
	fun_list[i](args, buf, fd);
}

void	ft_write_buf_fd(int fd, t_display_buffer_fd *buf, char const *str, int len)
{
	int	i;

	if (buf->offset < 0)
		return ;
	i = -1;
	while (++i < len)
	{
		buf->buffer[buf->offset++] = str[i];
		if (buf->offset == PRINTF_BUFFER_SIZE)
		{
			if (write(fd, buf->buffer, PRINTF_BUFFER_SIZE) < 0)
			{
				buf->offset = -1;
				return ;
			}
			else
			{
				buf->offset = 0;
				buf->total_length += PRINTF_BUFFER_SIZE;
			}
		}
	}
}

void	ft_printf_loop_fd(const char *format,
	va_list *args, t_display_buffer_fd *buf, int fd)
{
	int	len;
	int	i;

	i = 0;
	while (format[i] && buf->total_length >= 0)
	{
		len = 2;
		if (format[i] == '%')
		{
			if (format[i + 1])
				ft_fun_conv_fd(format[i + 1], args, buf, fd);
			else
				buf->total_length = -1;
		}
		else
		{
			len = 0;
			while (format[i + len] != '%' && format[i + len])
				len++;
			ft_write_buf_fd(fd, buf, format + i, len);
		}
		i += len;
	}
}

int	ft_printf_fd(int fd, const char *format, ...)
{
	va_list					args;
	t_display_buffer_fd		buf;

	buf.offset = 0;
	buf.total_length = 0;
	va_start(args, format);
	ft_printf_loop_fd(format, &args, &buf, fd);
	va_end(args);
	if (buf.offset < 0)
		return (-1);
	buf.total_length += buf.offset * (buf.total_length >= 0);
	if (write(fd, buf.buffer, buf.offset) < 0)
		return (-1);
	return (buf.total_length);
}
