/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_rgb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 23:41:15 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/31 10:50:05 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

/*
** Tracer une ligne en degrade
*/

void		draw_line_rgb(t_img *img, t_px *src, t_px *dst, int color)
{
	float	pasx;
	float	pasy;
	t_px	d;
	t_line	line;
	t_px	cur;

	line = draw_new_line(src, dst);
	d.x = (dst->x - src->x);
	d.y = (dst->y - src->y);
	pasx = (float)d.x / line.n;
	pasy = (float)d.y / line.n;
	line.n--;
	while (line.n >= 0)
	{
		cur.x = line.src.x + (pasx * line.n);
		cur.y = line.src.y + (pasy * line.n);
		draw_pixel_rgb(img, cur, color);
		line.n--;
	}
}
