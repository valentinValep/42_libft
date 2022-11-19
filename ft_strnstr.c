/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:11:33 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/19 13:56:13 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(const char *str);

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int			i;
	int			bl;
	const int	ll = ft_strlen(little);

	if (!*little)
		return ((char *)big);
	if ((!big && !len) || !*big)
		return (NULL);
	bl = ft_strlen(big);
	i = 0;
	len = (size_t []){len, bl}[len > (size_t)bl] - ll + 1;
	while ((int)len > 0)
	{
		while (big[i] == little[i] && big[i] && little[i])
			i++;
		if (i == ll)
			return ((char *)big);
		i = 0;
		big++;
		len--;
	}
	return (NULL);
}
