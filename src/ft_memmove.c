/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 02:27:19 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/08 18:14:18 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
// @TODO keep size_t or transform to unsigned int
void    *ft_memmove(void *dst, const void *src, size_t len)
{
    size_t                i;
    unsigned char        *pdst;
    const unsigned char    *psrc;

    pdst = (unsigned char *)dst;
    psrc = (unsigned char *)src;
    i = 0;
    if (psrc < pdst)
        while (++i <= len)
            pdst[len - i] = psrc[len - i];
    else
        while (len-- > 0)
            *(pdst++) = *(psrc++);
    return (dst);
}

// @TODO DEL
// ******************TESTS*******************

// @TODO DEL INCLUDES
#include <assert.h>
#include <string.h>
#include <stdio.h>

//void	*ft_memmove(void *dest, const void *src, long unsigned int n)
//{
//	return (memmove(dest, src, n));
//}

void	test_memmove(int n)
{
	char	src[] = "ZIZI";
	char	src2[] = "ZIZI";
	char	dest[5] = "CACA";
	char	dest2[5] = "CACA";
	char	*new = memmove(dest, src, n);
	char	*new2 = ft_memmove(dest2, src2, n);
	for (int i = 0; i < 5; i++)
		assert(dest[i] == dest2[i]);
	for (int i = 0; i < 5; i++)
		assert(new[i] == new2[i]);

	char	src8[] = "ZICAPITAMIXTAPE";
	char	src28[] = "ZICAPITAMIXTAPE";
	char	*dest8 = src8 + 2;
	char	*dest28 = src28 + 2;
	char	*new8 = memmove(dest8, src8, n);
	char	*new28 = ft_memmove(dest28, src28, n);
	for (int i = 0; i < 5; i++)
		assert(dest8[i] == dest28[i]);
	for (int i = 0; i < 5; i++)
		assert(new8[i] == new28[i]);

	char	dest89[] = "ZICAPITAMIXTAPE";
	char	dest289[] = "ZICAPITAMIXTAPE";
	char	*src89 = dest89 + 2;
	char	*src289 = dest289 + 2;
	char	*new89 = memmove(dest89, src89, n);
	char	*new289 = ft_memmove(dest289, src289, n);
	for (int i = 0; i < 5; i++)
		assert(dest89[i] == dest289[i]);
	for (int i = 0; i < 5; i++)
		assert(new89[i] == new289[i]);

	char	src878[] = "ZICAPITAMIXTAPE";
	char	src2878[] = "ZICAPITAMIXTAPE";
	char	*dest878 = src878;
	char	*dest2878 = src2878;
	char	*new878 = memmove(dest878, src878, n);
	char	*new2878 = ft_memmove(dest2878, src2878, n);
	for (int i = 0; i < 5; i++)
		assert(dest878[i] == dest2878[i]);
	for (int i = 0; i < 5; i++)
		assert(new878[i] == new2878[i]);

	//char	*src007 = NULL;
	//char	*src2007 = NULL;
	//char	*dest007 = NULL;
	//char	*dest2007 = NULL;
	//ft_memmove(dest2007, src2007, n);
	//memmove(dest007, src007, n);
}

int	main(void)
{
	test_memmove(0);
	test_memmove(1);
	test_memmove(4);
	printf("ft_memmove tests finished");
}
