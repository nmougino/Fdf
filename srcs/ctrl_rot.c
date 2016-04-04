/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 22:04:29 by nmougino          #+#    #+#             */
/*   Updated: 2016/04/04 23:16:51 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

void	ctrl_rot(t_meta *meta, int p)
{
	meta->angle += (double)p / 1000;
	meta->isocos = cos((double)(meta->angle / M_PI) * 180);
	meta->isosin = sin((double)(meta->angle / M_PI) * 180);
}
