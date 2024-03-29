/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 00:20:05 by vlepille          #+#    #+#             */
/*   Updated: 2022/12/21 00:27:16 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <unistd.h>
#include "libft_printf.h"

static void	ft_fun_conv(char c, va_list *args, t_display_buffer *buf)
{
	int					i;
	const char			format_list[CONVERSION_NUMBER] = "cspdiuxX%";
	t_fun_conv const	fun_list[CONVERSION_NUMBER] = {&ft_char_conv,
		&ft_string_conv, &ft_pointer_conv, &ft_decimal_conv, &ft_integer_conv,
		&ft_unsigned_conv, &ft_lower_hexa_conv, &ft_upper_hexa_conv,
		&ft_percent_conv};

	i = -1;
	while (++i < CONVERSION_NUMBER && format_list[i] != c)
		;
	if (i == CONVERSION_NUMBER)
	{
		ft_write_buf(buf, (char []){'%', c}, 2);
		return ;
	}
	fun_list[i](args, buf);
}

void	ft_write_buf(t_display_buffer *buf, char const *str, int len)
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
			if (write(STDOUT_FILENO, buf->buffer, PRINTF_BUFFER_SIZE) < 0)
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

void	ft_printf_loop(const char *format, va_list *args, t_display_buffer *buf)
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
				ft_fun_conv(format[i + 1], args, buf);
			else
				buf->total_length = -1;
		}
		else
		{
			len = 0;
			while (format[i + len] != '%' && format[i + len])
				len++;
			ft_write_buf(buf, format + i, len);
		}
		i += len;
	}
}

int	ft_printf(const char *format, ...)
{
	va_list					args;
	t_display_buffer		buf;

	buf.offset = 0;
	buf.total_length = 0;
	va_start(args, format);
	ft_printf_loop(format, &args, &buf);
	va_end(args);
	if (buf.offset < 0)
		return (-1);
	buf.total_length += buf.offset * (buf.total_length >= 0);
	if (write(STDOUT_FILENO, buf.buffer, buf.offset) < 0)
		return (-1);
	return (buf.total_length);
}
