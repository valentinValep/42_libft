/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:22:43 by vlepille          #+#    #+#             */
/*   Updated: 2023/10/04 16:48:46 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.h"
#include "libft.h"

void	print_vector(t_vector *vector, void (*print_func)(void *))
{
	int	i;

	i = -1;
	ft_printf("[\n", vector->len);
	while (++i < vector->len)
	{
		ft_printf("\t");
		print_func(vector->tab + (i * vector->elem_size));
		if (i != vector->len - 1)
			ft_printf("\n");
	}
	ft_printf("\n]\n");
}
