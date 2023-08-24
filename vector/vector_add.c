/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:33:05 by vlepille          #+#    #+#             */
/*   Updated: 2023/08/24 17:54:56 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include <stdlib.h>

int	upscale_tab(t_vector *vector, void **new_tab)
{
	int	i;

	vector->msize = (vector->msize << 1) + !vector->msize;
	*new_tab = malloc(vector->msize * vector->elem_size);
	if (!*new_tab)
		return (MALLOC_ERROR);
	i = -1;
	while (++i < vector->len * vector->elem_size)
		((char *)*new_tab)[i] = ((char *)vector->tab)[i];
	free(vector->tab);
	vector->tab = *new_tab;
	return (0);
}

int	add_vec(t_vector *vector, void *elem)
{
	void	*new_tab;
	int		i;

	if (vector->len + 1 > vector->msize)
	{
		i = upscale_tab(vector, &new_tab);
		if (i)
			return (i);
	}
	i = -1;
	while (++i < vector->elem_size)
		((char *)vector->tab)
		[vector->len * vector->elem_size + i] = ((char *)elem)[i];
	vector->len++;
	return (0);
}

int	add_vec_offset(t_vector *vector, void *elem, int offset)
{
	void	*new_tab;
	int		i;

	if (offset > vector->len)
		offset = vector->len;
	if (vector->len + 1 > vector->msize)
	{
		i = upscale_tab(vector, &new_tab);
		if (i)
			return (i);
	}
	ft_memmove(((char *)vector->tab) + ((offset + 1) * vector->elem_size),
		((char *)vector->tab) + (offset * vector->elem_size),
		(vector->len - offset) * vector->elem_size);
	i = -1;
	while (++i < vector->elem_size)
		((char *)vector->tab)[offset * vector->elem_size + i]
			= ((char *)elem)[i];
	vector->len++;
	return (0);
}
