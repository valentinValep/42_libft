/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 16:51:22 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/16 16:51:24 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	int_len(int n)
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

	i = int_len(n);
	res = malloc((i + 1) * sizeof(char));
	n < 0 && (res[0] = '-', 1);
	res[i] = 0;
	while (n != 0)
	{
		res[i - 1] = '0' + (n % 10) * ((n > 0) * 2 - 1);
		n = n / 10;
		i--;
	}
	return (res);
}
