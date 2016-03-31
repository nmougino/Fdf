/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 03:25:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/31 10:48:05 by nmougino         ###   ########.fr       */
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

static t_px	iso_getcurp(t_meta *meta, t_data *data, size_t x, int y)
{
	t_px	curp;
	int		z;

	z = data->data[x];
	curp.x = meta->pto.x +
		(meta->pta.x * (x * meta->ptaa.x + y * meta->ptaa.y));
	curp.y = meta->pto.y +
		(meta->pta.y * (y * meta->ptaa.y - x * meta->ptaa.x))
		+ (-z * meta->coefz);
	if (z == 0)
		curp.color = meta->graph.y == 0 ? 0.333 : 0;
	else if (z < 0)
		curp.color = meta->graph.y == 0 ?
			0.667 - (0.333 / (1 + ((float)z / 10))) : 0;
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
			draw_pixel(meta->img, (*line)[i]);
		else
			draw_pixel_rgb(meta->img, (*line)[i], 0xFFFFFF);
	}
}

void		iso(t_meta *meta)
{
	int		y;
	size_t	i;
	size_t	prevsize;
	t_data	*data;
	t_px	**line;

	if (!(line = (t_px**)malloc(sizeof(t_px*) * 2)))
		return ;
	data = meta->data[meta->arg];
	line[0] = NULL;
	y = 0;
	prevsize = 0;
	while (data && ((line[1] = (t_px*)malloc(sizeof(t_px) * (data->size + 1)))))
	{
		i = 0;
		while (i < data->size)
		{
			line[1][i] = iso_getcurp(meta, data, i, y);
			iso_conv(meta, line, i++, prevsize);
		}
		iso_free(line);
		line[0] = line[1];
		prevsize = data->size;
		data = data->next;
		y++;
	}
	iso_free(line);
}
