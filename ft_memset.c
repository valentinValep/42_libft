/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 21:03:40 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/08 16:17:30 by vlepille         ###   ########.fr       */
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

void	test_memset(int c)
{
	char	str[] = "ZIZI";
	char	str2[] = "ZIZI";
	char	*new = memset(str, c, 4);
	char	*new2 = ft_memset(str2, c, 4);
	for (int i = 0; i < 5; i++)
		assert(str[i] == str2[i]);
	for (int i = 0; i < 5; i++)
		assert(new[i] == new2[i]);
}

int	main(void)
{
	test_memset(0);
	test_memset('z');
	test_memset(128);
	test_memset(-1);
	test_memset(-128);
	test_memset(-129);
	test_memset(3273);
	printf("ft_memset tests finished");
}
