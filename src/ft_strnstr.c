/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:11:33 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/10 02:44:10 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// @TODO implements
#include <bsd/string.h>
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	return (strnstr(big, little, len));
}

//char	*ft_strstr(char *str, char *to_find)
//{
//	int	i;
//	int	j;

//	i = 0;
//	j = 0;
//	if (!to_find[0])
//		return (str);
//	while (str[i])
//	{
//		if (str[i] == to_find[0])
//		{
//			while (str[j + i] == to_find[j] && to_find[j] && str[j + i])
//			{
//				j++;
//			}
//			if (!to_find[j])
//				return (str + i);
//			j = 0;
//		}
//		i++;
//	}
//	return (NULL);
//}
