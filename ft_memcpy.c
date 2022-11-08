/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 02:27:19 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/08 16:05:24 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// @TODO keep size_t or transform to unsigned int
void	*ft_memcpy(void *dest, const void *src, long unsigned int n);


// @TODO DEL
// ******************TESTS*******************

// @TODO DEL INCLUDES
#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stddef.h>

void	*ft_memcpy(void *dest, const void *src, long unsigned int n)
{
	return (memcpy(dest, src, n));
}

void	test_memcpy(int n)
{
	char	src[] = "ZIZI";
	char	src2[] = "ZIZI";
	char	dest[5] = "CACA";
	char	dest2[5] = "CACA";
	char	*new = memcpy(dest, src, n);
	char	*new2 = ft_memcpy(dest2, src2, n);
	for (int i = 0; i < 5; i++)
		assert(dest[i] == dest2[i]);
	for (int i = 0; i < 5; i++)
		assert(new[i] == new2[i]);

	char	src8[] = "ZICAPITAMIXTAPE";
	char	src28[] = "ZICAPITAMIXTAPE";
	char	*dest8 = src8 + 2;
	char	*dest28 = src28 + 2;
	char	*new8 = memcpy(dest8, src8, n);
	char	*new28 = ft_memcpy(dest28, src28, n);
	for (int i = 0; i < 5; i++)
		assert(dest8[i] == dest28[i]);
	for (int i = 0; i < 5; i++)
		assert(new8[i] == new28[i]);

	char	dest89[] = "ZICAPITAMIXTAPE";
	char	dest289[] = "ZICAPITAMIXTAPE";
	char	*src89 = dest89 + 2;
	char	*src289 = dest289 + 2;
	char	*new89 = memcpy(dest89, src89, n);
	char	*new289 = ft_memcpy(dest289, src289, n);
	for (int i = 0; i < 5; i++)
		assert(dest89[i] == dest289[i]);
	for (int i = 0; i < 5; i++)
		assert(new89[i] == new289[i]);
}

int	main(void)
{
	test_memcpy(0);
	test_memcpy(1);
	test_memcpy(4);
	printf("ft_memcpy tests finished");
}
