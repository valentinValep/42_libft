/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:43:06 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/16 10:04:06 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	const int	res_len = -~(ft_strlen(s1) + ft_strlen(s2));
	char *const	res = malloc(res_len * sizeof(char));

	if (!res)
		return (0);
	ft_strlcpy(res, s1, res_len);
	ft_strlcat(res, s2, res_len);
	return (res);
}
