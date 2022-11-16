/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:45:53 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/16 14:33:28 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	is_in(const char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*res;

	while (is_in(*s1, set))
		s1++;
	i = ft_strlen(s1) - 1;
	while (is_in(s1[i], set) && i > 0)
		i--;
	if (i <= 0)
	{
		res = malloc(sizeof(char));
		if (!res)
			return (0);
		*res = 0;
		return (res);
	}
	res = malloc((i + 2) * sizeof(char));
	if (!res)
		return (0);
	ft_strlcpy(res, s1, i + 2);
	return (res);
}
