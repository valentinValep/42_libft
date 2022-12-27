/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:46:04 by vlepille          #+#    #+#             */
/*   Updated: 2022/12/27 19:10:40 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	count_word(char const *s, char c)
{
	int	in_word;
	int	count;

	in_word = 0;
	count = 0;
	while (*s)
	{
		if (!in_word && *s != c)
		{
			in_word = 1;
			count++;
		}
		else if (in_word && *s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

static int	str_len_sep(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

void	free_split(char **str_split, int len)
{
	while (len > 0)
	{
		free(str_split[len - 1]);
		len--;
	}
	free(str_split);
}

char	**ft_split(char const *s, char c)
{
	int				res_i;
	int				current_word_len;
	char **const	res = malloc((-~count_word(s, c)) * sizeof(char *));

	if (!res)
		return (0);
	res_i = 0;
	while (*s)
	{
		if (*s != c || (s++, 0))
		{
			current_word_len = str_len_sep(s, c);
			res[res_i] = ft_substr(s, 0, current_word_len);
			if (!res[res_i])
			{
				free_split(res, res_i);
				return (0);
			}
			res_i++;
			s += current_word_len;
		}
	}
	res[res_i] = 0;
	return (res);
}
