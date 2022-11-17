/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:41:55 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/17 18:10:16 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_substr(char const *s, unsigned int st, size_t len)
{
	int const	max_len = (int []){ft_strlen(s) -st, 0}[st > ft_strlen(s)];
	int const	res_len = (size_t []){len, max_len}[(int)len > max_len];
	char *const	res = malloc((res_len + 1) * sizeof(char));

	if (!res)
		return (0);
	res[res_len] = 0;
	return (ft_memcpy(res, s + st, res_len));
}
