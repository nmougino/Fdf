/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/24 17:18:46 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/31 16:16:01 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	err_open(char *file)
{
	ft_putendl("\033[1m\033[31mERREUR *** IMPOSSIBLE D'OUVRIR LE FICHIER");
	ft_putstr("     -> argument : ");
	ft_putstr(file);
	ft_putendl("\033[0m");
}

void	err_input(void)
{
	ft_putendl("\033[1m\033[31mERREUR *** AUCUN PARAMETRE");
	ft_putendl("\033[0m");
}

void	err_nodata(char *file)
{
	ft_putendl("\033[1m\033[31mERREUR *** AUCUNE DONNEES");
	ft_putstr("     -> argument : ");
	ft_putstr(file);
	ft_putendl("\033[0m");
}
