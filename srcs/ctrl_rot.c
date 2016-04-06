/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_rot.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 22:04:29 by nmougino          #+#    #+#             */
/*   Updated: 2016/04/06 22:30:52 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline void	ctrl_rot(t_meta *meta, int p)
{
	meta->angle += (double)p / 2500;
	meta->isocos = cos((double)(meta->angle / M_PI) * 180);
	meta->isosin = sin((double)(meta->angle / M_PI) * 180);
}
