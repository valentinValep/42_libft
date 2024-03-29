/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:33:05 by vlepille          #+#    #+#             */
/*   Updated: 2023/10/04 16:39:14 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include <stdlib.h>

int	upscale_tab(t_vector *vector, void **new_tab)
{
	int	i;

	if (vector->msize == -1)
		return (ALREADY_FAIL_ERROR);
	vector->msize = (vector->msize << 1) + !vector->msize;
	*new_tab = malloc(vector->msize * vector->elem_size);
	if (!*new_tab)
	{
		vector->msize = -1;
		return (MALLOC_ERROR);
	}
	i = -1;
	while (++i < vector->len * vector->elem_size)
		((char *)*new_tab)[i] = ((char *)vector->tab)[i];
	free(vector->tab);
	vector->tab = *new_tab;
	return (0);
}

int	push_vec(t_vector *vector, void *elem)
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

int	push_vec_offset(t_vector *vector, void *elem, int offset)
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
