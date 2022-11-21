/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:03:40 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/21 11:02:22 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *pointer, int value, size_t size)
{
	if (!size)
		return (pointer);
	while (size > 0)
		((char *)pointer)[--size] = (char) value;
	return (pointer);
}

//void	*ft_memset(void *pointer, int value, size_t size)
//{
//	if (!size)
//		return (pointer);
//	*(char *)pointer = (char) value;
//	ft_memset(pointer + 1, value, size - 1);
//	return (pointer);
//}
