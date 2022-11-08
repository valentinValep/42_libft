/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:03:40 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/08 21:37:04 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// @TODO keep size_t or transform to unsigned int
void	*ft_memset(void *s, int c, long unsigned int n);


// @TODO DEL
// ******************TESTS*******************

// @TODO DEL INCLUDES
#include  <assert.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

void	*ft_memset(void *s, int c, long unsigned int n)
{
	return (memset(s, c, n));
}
