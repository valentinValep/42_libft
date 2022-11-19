/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 02:27:19 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/19 16:35:52 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	int	i;

	if (!size || (!dest && !src))
		return (dest);
	i = (size - 1) * (dest >= src);
	while (size)
	{
		((char *)dest)[i] = ((char *)src)[i];
		size--;
		i += (dest < src) * 2 - 1;
	}
	return (dest);
}

//void	*ft_memmove(void *dest, const void *src, size_t size)
//{
//	if (!size)
//		return (dest);
//	if (dest < src)
//		*(char *)dest = *(char *)src;
//	ft_memmove(dest + 1, src + 1, --size);
//	if (dest > src)
//		*(char *)dest = *(char *)src;
//	return (dest);
//}
