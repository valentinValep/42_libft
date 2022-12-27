/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_gnl.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 21:19:10 by marvin            #+#    #+#             */
/*   Updated: 2022/12/27 19:09:43 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_GNL_H
# define LIBFT_GNL_H

# include "str/libft_str.h"

# ifndef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 42
# endif

# if GNL_BUFFER_SIZE < 0
#  undef GNL_BUFFER_SIZE
#  define GNL_BUFFER_SIZE 0
# endif

typedef struct s_file_reader
{
	char	*str;
	int		strlen;
	int		line_offset;
}	t_file_reader;

char	*get_next_line(int fd);

#endif
