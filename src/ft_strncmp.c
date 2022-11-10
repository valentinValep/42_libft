/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:05:15 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/10 02:05:26 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strncmp(const char *first, const char *second, size_t length)
{
	int	comp;

	comp = *first - *second;
	if ((!*first && !*second) || !length)
		return (0);
	if (comp != 0)
		return (comp);
	return (ft_strncmp(first + 1, second + 1, length - 1));
}
