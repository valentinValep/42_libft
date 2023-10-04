/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fun_conv_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 12:17:05 by vlepille          #+#    #+#             */
/*   Updated: 2023/10/04 16:56:18 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf_fd.h"

static void	ft_putnbr_fd(int nbr, t_display_buffer_fd *buf, int fd)
{
	if (nbr / 10)
		ft_putnbr_fd(nbr / 10, buf, fd);
	else
		ft_write_buf_fd(fd, buf, "-", nbr < 0);
	ft_write_buf_fd(fd, buf, &(char){nbr % 10 * ((nbr > 0) * 2 -1) + '0'}, 1);
}

static void	ft_putnbr_unsigned_fd(
	unsigned int nbr, t_display_buffer_fd *buf, int fd)
{
	if (nbr / 10)
		ft_putnbr_unsigned_fd(nbr / 10, buf, fd);
	ft_write_buf_fd(fd, buf, &(char){nbr % 10 + '0'}, 1);
}

void	ft_decimal_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd)
{
	int	input;

	input = (int)va_arg(*args, int);
	ft_putnbr_fd(input, buf, fd);
}

void	ft_integer_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd)
{
	int	input;

	input = (int)va_arg(*args, int);
	ft_putnbr_fd(input, buf, fd);
}

void	ft_unsigned_conv_fd(va_list *args, t_display_buffer_fd *buf, int fd)
{
	int	input;

	input = (int)va_arg(*args, int);
	ft_putnbr_unsigned_fd(input, buf, fd);
}
