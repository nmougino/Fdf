/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 02:59:55 by nmougino          #+#    #+#             */
/*   Updated: 2016/04/06 22:59:49 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline void	ctrl_zoom(t_meta *meta, int p)
{
	int	coef;

	coef = 1;
	if (meta->datamax[meta->arg].x < 300 || meta->datamax[meta->arg].y < 300)
		coef = 3;
	((meta->pta.x += (p * meta->coefz) * 3) < 3 * coef) ?
		meta->pta.x = 3 * coef : meta->pta.x;
	((meta->pta.y += (p * meta->coefz)) < 1 * coef) ?
		meta->pta.y = 1 * coef : meta->pta.y;
	meta->zaa = (meta->pta.y / 2) < 1 ? 1 : meta->pta.y / 2;
}
