/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 01:20:47 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/08 02:33:33 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// @TODO keep size_t or transform to long unsigned int
// use memset(s, 0, n)
void	ft_bzero(void *s, long unsigned int n);


// @TODO DEL
// ******************TESTS*******************

// @TODO DEL INCLUDES
#include  <assert.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

void	ft_bzero(void *s, long unsigned int n)
{
	bzero(s, n);
}

// max 5
void	test_bzero(long unsigned int n)
{
	char	str[] = "ZIZI";
	char	str2[] = "ZIZI";
	bzero(str, n);
	ft_bzero(str2, n);
	for (int i = 0; i < 5; i++)
		assert(str[i] == str2[i]);
}

int	main(void)
{
	test_bzero(0);
	test_bzero(1);
	test_bzero(4);
	printf("ft_bzero tests finished");
}
