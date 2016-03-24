/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:18:46 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/24 17:19:14 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err_open(int i)
{
	ft_putendl("\033[1m\033[31m *** IMPOSSIBLE D'OUVRIR LE FICHIER");
	ft_putstr("     -> argument : ");
	ft_putnbr(i);
	ft_putendl("\033[0m");
}

void	err_nodata(int i)
{
	ft_putendl("\033[1m\033[31m *** AUCUNE DONNEES");
	ft_putstr("     -> argument : ");
	ft_putnbr(i);
	ft_putendl("\033[0m");
}
