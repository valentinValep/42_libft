/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 02:27:19 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/19 14:28:14 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	if (!size)
		return (dest);
	if (dest < src)
		*(char *)dest = *(char *)src;
	ft_memmove(dest + 1, src + 1, --size);
	if (dest > src)
		*(char *)dest = *(char *)src;
	return (dest);
}

int main()
{
	char *str = malloc(sizeof * str * 128 * 1024 * 1024);
	char *dst = malloc(sizeof * str * 128 * 1024 * 1024);
	if (!str || ! dst)
		return (NULL);
	ft_memset(dst, 'A', 128 * 1024 * 1024);
	ft_memmove(str, dst, 128 * 1024 * 1024);
	printf("%p", str);
}