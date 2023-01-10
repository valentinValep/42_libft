/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:19:10 by marvin            #+#    #+#             */
/*   Updated: 2023/01/10 14:41:31 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STR_H
# define LIBFT_STR_H

typedef struct s_string
{
	char	*str;
	int		strlen;
	int		malloc_size;
}	t_string;

int		ft_init_string(t_string *str, char *base_str);
void	ft_upscale_string(t_string *str, int size);
int		ft_cat_string(t_string *str, char *base_str);
void	ft_destroy_string(t_string *str);

#endif
