/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:05:15 by vlepille          #+#    #+#             */
/*   Updated: 2023/09/21 14:46:04 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(const char *first, const char *second)
{
	int	comp;

	comp = (unsigned char)*first - (unsigned char)*second;
	if (comp != 0 || (!*first && !*second))
		return (comp);
	return (ft_strcmp(first + 1, second + 1));
}
