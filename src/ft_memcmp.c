/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:09:02 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/10 02:29:19 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// @TODO implements
#include <string.h>
int	ft_memcmp(const void *pointer1, const void *pointer2, size_t size)
{
	return (memcmp(pointer1, pointer2, size));
}
