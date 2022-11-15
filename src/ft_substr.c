/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:41:55 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/15 19:11:09 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	const int	max_len = (int []){ft_strlen(s) - \
		start, 0}[(int)(ft_strlen(s) - start) < 0];
	int const	res_len = (size_t []){len, max_len}[(int)len > max_len];
	char *const	res = malloc((res_len + 1) * sizeof(char));

	res[res_len] = 0;
	return (ft_memcpy(res, s + start, res_len));
}

//// @TODO Implements
//char	*ft_substr(char const *s, unsigned int start, size_t len)
//{
//	if (s && start && len)
//		return (NULL);
//	return (NULL);
//}
