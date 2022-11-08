/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 02:45:48 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/08 02:51:54 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// @TODO refaire

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

#include <stddef.h>

size_t	ft_strlcat(char *dest, char *src, size_t size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			res;

	res = ft_strlen(src) + ft_strlen(dest);
	i = 0;
	while (dest[i] && i < size)
		i++;
	j = 0;
	if (i >= size)
		return (ft_strlen(src) + size);
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (res);
}

#include <string.h>
#include <stdio.h>
#include <bsd/string.h>
int main()
{
    char dst[7] = "000";
    char src[7] = "123";
    char dst1[7] = "000";
    char src1[7] = "123";
    printf("my: return:%ld, dest:%s\n",ft_strlcat(dst,src,8), dst);
    printf("real: return:%ld, dest:%s\n\n",strlcat(dst1,src1,8), dst1);

    char dst2[7] = "";
    char src2[7] = "123";
    char dst3[7] = "";
    char src3[7] = "123";
    printf("my: return:%ld, dest:%s\n", ft_strlcat(dst2,src2,2), dst2);
    printf("real: return:%ld, dest:%s\n\n", strlcat(dst3,src3,2), dst3);

    char dst4[7] = "000";
    char src4[7] = "";
    char dst5[7] = "000";
    char src5[7] = "";
    printf("my: return:%ld, dest:%s\n", ft_strlcat(dst4,src4,7), dst4);
    printf("real: return:%ld, dest:%s\n\n", strlcat(dst5,src5,7), dst5);

    char dst6[7] = "000";
    char src6[7] = "123";
    char dst7[7] = "000";
    char src7[7] = "123";
    printf("my: return:%ld, dest:%s\n", ft_strlcat(dst6,src6,0), dst6);
    printf("real: return:%ld, dest:%s\n\n", strlcat(dst7,src7,0), dst7);

    char dst8[7] = "1";
    char src8[7] = "123";
    char dst9[7] = "1";
    char src9[7] = "123";
    printf("my: return:%ld, dest:%s\n", ft_strlcat(dst8,src8,2), dst8);
    printf("real: return:%ld, dest:%s\n\n", strlcat(dst9,src9,2), dst9);
}