/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 23:41:15 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/28 21:46:06 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

/*
** Tracer une ligne en degrade
*/

static void	draw_the_line(float pasx, float pasy, t_img *img, t_line line)
{
	t_px	cur;
	int		i;

	i = 0;
	while (i < line.n)
	{
		cur.x = line.src.x + (pasx * i);
		cur.y = line.src.y + (pasy * i);
		cur.color = draw_line_curcolor(line, cur);
		draw_pixel(img, cur);
		i++;
	}
}

void		draw_line(t_img *img, t_px *src, t_px *dst)
{
	float	pasx;
	float	pasy;
	t_px	d;
	t_line	line;

	line = draw_new_line(src, dst);
	d.x = (dst->x - src->x);
	d.y = (dst->y - src->y);
	pasx = (float)d.x / line.n;
	pasy = (float)d.y / line.n;
	draw_the_line(pasx, pasy, img, line);
}
