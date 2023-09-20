/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 14:23:23 by vlepille          #+#    #+#             */
/*   Updated: 2023/09/20 14:27:15 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_more.h"

int	is_whitespace(char c)
{
	return ((c >= '\t' && c <= '\r') || c == ' ');
}

int	is_whitespace_no_newline(char c)
{
	return (is_whitespace(c) && c != '\n');
}
