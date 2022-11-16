/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 04:37:48 by vlepille          #+#    #+#             */
/*   Updated: 2022/11/16 19:12:31 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>
#include "libft.h"

// @TODO TRY WITH
// if (size != 0 && nmemb * size / size != nmemb)
// INSTEAD OF
// if (nmemb * size > SIZE_MAX)
// FOR ONLINE TESTERS
void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*res;

	if (nmemb * size > SIZE_MAX)
		return (NULL);
	res = malloc(nmemb * size);
	if (!res)
		return (0);
	ft_bzero(res, nmemb * size);
	return (res);
}
