/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_conv_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:17:07 by vlepille          #+#    #+#             */
/*   Updated: 2022/12/21 00:26:27 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft_printf.h"

void	ft_char_conv(va_list *args, t_display_buffer *buf)
{
	ft_write_buf(buf, &(char){va_arg(*args, int)}, 1);
}

void	ft_string_conv(va_list *args, t_display_buffer *buf)
{
	int		i;
	char	*str;

	str = (char *)va_arg(*args, char const *);
	if (!str)
	{
		ft_write_buf(buf, "(null)", 6);
		return ;
	}
	i = -1;
	while (str[++i])
		;
	ft_write_buf(buf, str, i);
}

void	ft_percent_conv(va_list *args, t_display_buffer *buf)
{
	(void)args;
	ft_write_buf(buf, "%", 1);
}
