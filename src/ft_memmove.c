/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 02:27:19 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/14 17:00:59 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	if (!size)
		return (dest);
	(dest < src && (*(char *)dest = *(char *)src, 1));
	ft_memmove(dest + 1, src + 1, size - 1);
	(dest > src && (*(char *)dest = *(char *)src, 1));
	return (dest);
}
