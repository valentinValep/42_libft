/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:37:48 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/10 04:41:36 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

// @TODO implements and remove includes
#include <stdlib.h>
void	*ft_calloc(size_t nmemb, size_t size)
{
	return (calloc(nmemb, size));
}
