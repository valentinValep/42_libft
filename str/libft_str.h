/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_str.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:19:10 by marvin            #+#    #+#             */
/*   Updated: 2022/12/21 00:22:01 by vlepille         ###   ########.fr       */
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

void	ft_upscale_str(t_string *str, int size);

#endif
