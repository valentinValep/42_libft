/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:05:15 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/15 16:51:40 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strlen(const char *str);

char	*ft_strrchr(const char *string, int searchedChar)
{
	const char	*f = string + ft_strlen(string);

	if (!searchedChar)
		return ((char *)f);
	while (f >= string)
	{
		if (*f == (char)searchedChar)
			return ((char *)f);
		f--;
	}
	return (NULL);
}
