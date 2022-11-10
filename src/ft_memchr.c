/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:09:02 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/10 02:29:13 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *memoryBlock, int searchedChar, size_t size)
{
	return (memchr(memoryBlock, searchedChar, size));
}
