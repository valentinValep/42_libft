/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:04:02 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/15 16:17:52 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

char	*ft_strchr(const char *s, int c)
{
	if (*s)
		return ((char *[]){ft_strchr(s + 1, c), (char *)s}[*s == (char)c]);
	return ((char *[]){NULL, (char *)s}[(char)c == '\0']);
}
