/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:46:50 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/19 10:02:46 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (n / 10)
		ft_putnbr_fd(n / 10, fd);
	else
		write(fd, "-", n < 0);
	write(fd, &(char){n % 10 *~-((n > 0) * 2) + 48}, 1);
}
