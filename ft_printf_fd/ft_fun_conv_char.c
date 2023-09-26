/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_conv_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:17:07 by vlepille          #+#    #+#             */
/*   Updated: 2023/09/26 16:59:55 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_fd.h"

void	ft_char_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd)
{
	ft_write_buf_fd(fd, buf, &(char){va_arg(*args, int)}, 1);
}

void	ft_string_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd)
{
	int		i;
	char	*str;

	str = (char *)va_arg(*args, char const *);
	if (!str)
	{
		ft_write_buf_fd(fd, buf, "(null)", 6);
		return ;
	}
	i = -1;
	while (str[++i])
		;
	ft_write_buf_fd(fd, buf, str, i);
}

void	ft_percent_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd)
{
	(void)args;
	ft_write_buf_fd(fd, buf, "%", 1);
}
