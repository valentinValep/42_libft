/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 02:27:19 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/08 23:17:38 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// @TODO implements
#include <string.h>
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	return (memcpy(dest, src, n));
}
