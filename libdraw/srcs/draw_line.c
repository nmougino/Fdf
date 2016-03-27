/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 23:41:15 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/27 04:28:56 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

/*
** Tracer une ligne en degrade
*/

void	draw_ver_line(t_img *img, t_line line)
{
	t_px	cur;
	t_px	end;

	cur = (line.src.y < line.dst.y) ? line.src : line.dst;
	end = (line.src.y < line.dst.y) ? line.dst : line.src;
	while (cur.y != end.y)
	{
		cur.color = draw_line_curcolor(line, cur);
		draw_pixel(img, cur);
		cur.y++;
	}
}

void	draw_hor_line(t_img *img, t_line line)
{
	t_px	cur;
	t_px	end;

	cur = (line.src.x < line.dst.x) ? line.src : line.dst;
	end = (line.src.x < line.dst.x) ? line.dst : line.src;
	while (cur.x != end.x)
	{
		cur.color = draw_line_curcolor(line, cur);
		draw_pixel(img, cur);
		cur.x++;
	}
}

void	draw_bresenham(t_img *img, t_line line)
{
	int		e;
	t_px	inc;
	t_px	cur;

	inc.x = (line.dst.x - line.src.x < 0) ? -1 : 1;
	inc.y = (line.dst.y - line.src.y < 0) ? -1 : 1;
	e = -line.dx >> 1;
	cur = line.src;
	while (cur.x != line.dst.x)
	{
		cur.color = draw_line_curcolor(line, cur);
		draw_pixel(img, cur);
		e += line.dy;
		while (e > 0)
		{
			draw_pixel(img, cur);
			cur.color = draw_line_curcolor(line, cur);
			e -= line.dx;
			cur.y += inc.y;
		}
		cur.x += inc.x;
	}
}

void	draw_line(t_img *img, t_px *src, t_px *dst)
{
	t_line	line;

	line = draw_new_line(src, dst);
	if (line.dx <= 1 && line.dy <= 1)
	{
		draw_pixel(img, *src);
		draw_pixel(img, *dst);
	}
	else if (line.dx == 0)
		draw_ver_line(img, line);
	else if (line.dy == 0)
		draw_hor_line(img, line);
	else
		draw_bresenham(img, line);
}
