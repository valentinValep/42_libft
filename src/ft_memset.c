/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:03:40 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/08 23:14:04 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// @TODO IMPLEMENTS
#include <string.h>
void	*ft_memset(void *pointer, int value, size_t count)
{
	return (memset(pointer, value, count));
}
