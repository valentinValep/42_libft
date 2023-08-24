/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 12:45:50 by vlepille          #+#    #+#             */
/*   Updated: 2022/12/29 12:47:14 by vlepille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_abs(int nbr)
{
	return (nbr * ((nbr > 0) * 2 - 1));
}

double	ft_abs_double(double nbr)
{
	return (nbr * ((nbr > 0) * 2 - 1));
}