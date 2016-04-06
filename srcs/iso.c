/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 03:25:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/04/05 16:07:09 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	iso_free(t_px **ptr)
{
	if (*ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static t_px	iso_getcurp(t_meta *meta, t_data *data, int x, int y)
{
	t_px	curp;
	int		z;

	z = data->data[x];
	x -= (meta->datamax[meta->arg].x / 2);
	y -= (meta->datamax[meta->arg].y / 2);
	curp.x = meta->pto.x +
	(int)(meta->pta.x) * ((x * meta->ptaa.x * meta->isocos)
			+ (y * meta->ptaa.y * meta->isosin));
	curp.y = meta->pto.y +
	(int)(meta->pta.y) * ((y * meta->ptaa.y * meta->isocos)
			- (x * meta->ptaa.x * meta->isosin))
		+ (-z * meta->coefz * meta->zaa);
	if (z == 0)
		curp.color = meta->graph.y == 0 ? 0.333 : 0;
	else if (z < 0)
	{
		curp.color = meta->graph.y == 0 ?
			0.333 * (1 - ((float)z / 20)) : 0;
		curp.color > 0.667 ? curp.color = 0.667 : 0;
	}
	else
		curp.color = meta->graph.y == 0 ?
			0.333 / (1 + ((float)z / 10)) : 0;
	return (curp);
}

static void	iso_conv(t_meta *meta, t_px **line, size_t i, size_t prevsize)
{
	if (meta->graph.x == 0)
		if (meta->graph.y == 0)
		{
			if (i > 0)
				draw_line(meta->img, line[1] + i, line[1] + i - 1);
			if (i < prevsize)
				draw_line(meta->img, line[1] + i, line[0] + i);
		}
		else
		{
			if (i > 0)
				draw_line_rgb(meta->img, line[1] + i,
						line[1] + i - 1, 0xFFFFFF);
			if (i < prevsize)
				draw_line_rgb(meta->img, line[1] + i, line[0] + i, 0xFFFFFF);
		}
	else
	{
		if (meta->graph.y == 0)
			draw_pixel(meta->img, line[1][i]);
		else
			draw_pixel_rgb(meta->img, line[1][i], 0xFFFFFF);
	}
}

void		iso(t_meta *meta)
{
	t_px	datapt;
	t_data	*data;
	t_px	**line;

	if (!(line = (t_px**)malloc(sizeof(t_px*) * 2)))
		return ;
	data = meta->data[meta->arg];
	line[0] = NULL;
	datapt.y = 0;
	meta->prevsize = 0;
	while (data && ((line[1] = (t_px*)malloc(sizeof(t_px) * (data->size + 1)))))
	{
		datapt.x = 0;
		while (datapt.x < data->size)
		{
			line[1][datapt.x] = iso_getcurp(meta, data, datapt.x, datapt.y);
			iso_conv(meta, line, datapt.x++, meta->prevsize);
		}
		iso_free(line);
		line[0] = line[1];
		meta->prevsize = data->size;
		data = data->next;
		datapt.y++;
	}
	iso_free(line);
}
