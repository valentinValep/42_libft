/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 23:34:17 by vlepille          #+#    #+#             */
/*   Updated: 2023/01/10 15:16:13 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_str.h"
#include <stddef.h>
#include <stdlib.h>

/*
Upscale the size of the string memory allocation to correspond with size + 1
*/
void	ft_upscale_string(t_string *str, int size)
{
	char	*new;
	int		i;

	if (str->malloc_size > size)
		return ;
	while (str->malloc_size <= size)
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

int	ft_init_string(t_string *str, char *base_str)
{
	int	i;

	str->strlen = 0;
	while (base_str && base_str[str->strlen])
		str->strlen++;
	str->malloc_size = 1;
	while (str->malloc_size <= str->strlen)
		str->malloc_size *= 2;
	str->str = malloc(str->malloc_size * sizeof(char));
	if (!str->str)
		return (-1);
	i = -1;
	while (++i < str->strlen)
		str->str[i] = base_str[i];
	str->str[i] = 0;
	return (0);
}

int	ft_cat_string(t_string *str, char *base_str)
{
	int	i;
	int	j;

	if (!str->str)
		return (ft_init_string(str, base_str));
	i = 0;
	while (base_str && base_str[i]) // @TODO THINK ABOUT base_str NULL
		i++;
	j = str->strlen;
	str->strlen = str->strlen + i;
	ft_upscale_string(str, str->strlen);
	if (!str->str)
		return (-1);
	i = 0;
	while (j < str->strlen)
	{
		str->str[j] = base_str[i];
		i++;
		j++;
	}
	str->str[str->strlen] = 0;
	return (0);
}

void	ft_destroy_string(t_string *str)
{
	if (str->str)
		free(str->str);
	str->str = NULL;
	str->malloc_size = 0;
	str->strlen = 0;
}
