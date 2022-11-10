/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 02:27:19 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/09 02:07:59 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
// @TODO implements
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*pdst;
	const unsigned char	*psrc;

	pdst = (unsigned char *)dest;
	psrc = (unsigned char *)src;
	i = 0;
	if (psrc < pdst)
		while (++i <= n)
			pdst[n - i] = psrc[n - i];
	else
		while (n-- > 0)
			*(pdst++) = *(psrc++);
	return (dest);
}
