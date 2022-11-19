/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:46:45 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/16 09:48:50 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stddef.h>

size_t	ft_strlen(const char *str);

void	ft_putendl_fd(char *s, int fd)
{
	(write(fd, s, ft_strlen(s)), write(fd, "\n", 1));
}
