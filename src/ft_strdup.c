/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:37:48 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/14 18:23:52 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);

char	*ft_strdup(const char *s)
{
	char	*res;

	res = malloc(ft_strlen(s) * sizeof(char) + 1);
	if (res)
		ft_strlcpy(res, s, ft_strlen(s) + 1);
	return (res);
}
