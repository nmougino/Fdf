/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel_rgb.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 10:51:00 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/31 10:51:01 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

void		draw_pixel_rgb(t_img *img, t_px pt, int color)
{
	if ((pt.x < img->width && pt.x >= 0) && (pt.y < img->height && pt.y >= 0))
	{
		*((int*)(unsigned long)(img->data + ((img->size_line * (pt.y))
						+ ((pt.x) * (img->bpp / 8))))) = color;
	}
}
