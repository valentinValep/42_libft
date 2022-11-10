/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 22:05:15 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/09 22:13:38 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// @TODO implements
#include <string.h>
char	*ft_strrchr(const char *string, int searchedChar)
{
	return (strrchr(string, searchedChar));
}
