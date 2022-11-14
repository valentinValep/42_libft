/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:09:02 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/14 17:01:27 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

//void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
//{
//	if (size)
//	{
//		if (*(char *)memoryBlock == (char)searchedChar)
//			return ((char *)memoryBlock);
//		return (ft_memchr((char *)memoryBlock + 1, searchedChar, ~ -size));
//	}
//	return (NULL);
//}

void	*ft_memchr(const void *p, int c, size_t s)
{
	if (s)
		return ((void *[]){ft_memchr((char *)p + 1, c, ~ -s),
			(char *)p}[(*(char *)p == (char)c)]);
	return (NULL);
}
