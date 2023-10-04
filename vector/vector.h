/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 16:17:10 by vlepille          #+#    #+#             */
/*   Updated: 2023/10/04 16:39:56 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H

# define MALLOC_ERROR 1
# define ALREADY_FAIL_ERROR 2

typedef struct s_vector
{
	void	*tab;
	int		elem_size;
	int		len;
	int		msize;
}	t_vector;

void	init_vec(t_vector *vector, int elem_size);
int		push_vec(t_vector *vector, void *elem)
		__attribute__ ((warn_unused_result));
int		push_vec_offset(t_vector *vector, void *elem, int offset)
		__attribute__ ((warn_unused_result));
int		join_vec(t_vector *vector, void *src, int len)
		__attribute__ ((warn_unused_result));
void	remove_vec(t_vector *vector, int offset);
void	destroy_vec(t_vector *vector);
void	destroy_vec2(t_vector *vector, void (*destroy_func)(void *));
void	print_vector(t_vector *vector, void (*print_func)(void *));

#endif
