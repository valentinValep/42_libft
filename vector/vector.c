/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:22:43 by vlepille          #+#    #+#             */
/*   Updated: 2023/10/04 16:55:48 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"
#include <stdlib.h>

void	init_vec(t_vector *vector, int elem_size)
{
	vector->len = 0;
	vector->elem_size = elem_size;
	vector->msize = 0;
	vector->tab = NULL;
}

void	remove_vec(t_vector *vector, int offset)
{
	vector->len--;
	offset *= vector->elem_size;
	while (offset < vector->len * vector->elem_size)
	{
		((char *)vector->tab)[offset]
			= ((char *)vector->tab)[offset + vector->elem_size];
		offset++;
	}
}

void	destroy_vec(t_vector *vector)
{
	if (vector->msize != 0)
		free(vector->tab);
	vector->len = 0;
	vector->msize = 0;
	vector->tab = NULL;
}

void	destroy_vec2(t_vector *vector, void (*destroy_func)(void *))
{
	int	i;

	i = -1;
	while (++i < vector->len)
		destroy_func(vector->tab + (i * vector->elem_size));
	destroy_vec(vector);
}

int	join_vec(t_vector *vector, void *src, int len)
{
	int	i;

	i = -1;
	while (++i < len)
		if (push_vec(vector, src + (i * vector->elem_size)))
			return (1);
	return (0);
}
