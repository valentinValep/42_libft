/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:09:02 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/17 14:30:50 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	int	comp;

	comp = *(unsigned char *)pointer1 - *(unsigned char *)pointer2;
	if (!size)
		return (0);
	if (comp != 0)
		return (comp);
	return (ft_memcmp(pointer1 + 1, pointer2 + 1, size - 1));
}
