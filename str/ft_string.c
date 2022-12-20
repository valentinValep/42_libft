/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:34:17 by vlepille          #+#    #+#             */
/*   Updated: 2022/12/21 00:28:56 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include <stddef.h>
#include <stdlib.h>

/*
Upscale the size of the string memory allocation to correspond with size
*/
void	ft_upscale_str(t_string *str, int size)
{
	char	*new;
	int		i;

	if (str->malloc_size >= size)
		return ;
	while (str->malloc_size < size)
		str->malloc_size = str->malloc_size * 2 + (!str->malloc_size);
	new = malloc((str->malloc_size) * sizeof(char));
	if (!new)
	{
		if (str->str)
			free(str->str);
		str->str = NULL;
		return ;
	}
	i = -1;
	while (++i < str->strlen)
		new[i] = str->str[i];
	new[i] = 0;
	free(str->str);
	str->str = new;
}
