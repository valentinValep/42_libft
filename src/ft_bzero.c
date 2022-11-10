/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 01:20:47 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/08 23:17:29 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// @TODO implements
// use memset(s, 0, n)
#include <strings.h>
void	ft_bzero(void *s, size_t n)
{
	bzero(s, n);
}
