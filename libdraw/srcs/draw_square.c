/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 13:09:22 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 19:00:03 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

/*
 **	pixel en haut a gauche, pixel en bas a droite,
 **	couleur, paramettre de remplissage.
 */

void	draw_empty_square(t_img *img, t_px p1, t_px p2, float color)
{
	t_px	cur;

	cur = p1;
	cur.color = color;
	while (cur.x < p2.x)
	{
		draw_pixel(img, cur);
		(cur.x)++;
	}
	while (cur.y < p2.y)
	{
		draw_pixel(img, cur);
		(cur.y)++;
	}
	while (cur.x > p1.x)
	{
		draw_pixel(img, cur);
		(cur.x)--;
	}
	while (cur.y > p1.y)
	{
		draw_pixel(img, cur);
		(cur.y)--;
	}
}

void		draw_square(t_img *img, t_px p1, t_px p2, float color)
{
	t_px	cur;

	cur = p1;
	cur.color = color;
	while (cur.y <= p2.y)
	{
		cur.x = p1.x;
		while (cur.x <= p2.x)
		{
			draw_pixel(img, cur);
			(cur.x)++;
		}
		(cur.y)++;
	}
}
