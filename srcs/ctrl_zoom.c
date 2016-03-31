/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 02:59:55 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/31 19:12:12 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline void	ctrl_zoom(t_meta *meta, int p)
{
	ft_putendl("chiffres:");
	ft_putnbrendl(((meta->pta.x += p * 3) < 3) ? meta->pta.x = 3 : meta->pta.x);
	ft_putnbrendl(((meta->pta.y += p) < 1) ? meta->pta.y = 1 : meta->pta.y);
	meta->zaa = meta->pta.y;
}
