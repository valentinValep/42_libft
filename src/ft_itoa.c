/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:51:22 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/19 10:03:33 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	int_len(int n)
{
	if (n / 10)
	{
		return (1 + int_len(n / 10));
	}
	return (1 + (n < 0));
}

char	*ft_itoa(int n)
{
	char	*res;
	int		i;

	i = int_len(n) - 1 - (n < 0);
	res = malloc((i + 2 + (n < 0)) * sizeof(char));
	if (!res)
		return (0);
	if (n < 0)
		res[0] = '-';
	res[i + 1 + (n < 0)] = 0;
	while (i >= 0)
	{
		res[i + (n < 0)] = '0' + (n % 10) * ((n > 0) * 2 - 1);
		n = n / 10;
		i--;
	}
	return (res);
}
