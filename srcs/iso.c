/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 03:25:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/30 02:32:19 by nmougino         ###   ########.fr       */
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
		curp.color = meta->graph.y == 0 ? 0.333 : 0.16;
	else if (z < 0)
		curp.color = meta->graph.y == 0 ?
			0.667 - (0.333 / (1 + ((float)z / 10))) : 0.16;
	else
		curp.color = meta->graph.y == 0 ?
			0.333 / (1 + ((float)z / 10)) : 0.16;
	return (curp);
}

static void	iso_loop(t_meta *meta, t_data *data, t_px **line)
{
	int		y;
	size_t	i;
	size_t	prevsize;

	y = 0;
	prevsize = 0;
	while (data && ((line[1] = (t_px*)malloc(sizeof(t_px) * (data->size + 1)))))
	{
		i = 0;
		while (i < data->size)
		{
			line[1][i] = iso_getcurp(meta, data, i, y);
			if (i > 0)
				draw_line(meta->img, line[1] + i, line[1] + i - 1);
			if (i < prevsize)
				draw_line(meta->img, line[1] + i, line[0] + i);
			i++;
		}
		iso_free(line);
		line[0] = line[1];
		prevsize = data->size;
		data = data->next;
		y++;
	}
}

static void	iso_pointed(t_meta *meta, t_data *data, t_px **line)
{
	int		y;
	size_t	i;

	y = 0;
	while (data && (((*line) = (t_px*)malloc(sizeof(t_px) * (data->size + 1)))))
	{
		i = 0;
		while (i < data->size)
		{
			(*line)[i] = iso_getcurp(meta, data, i, y);
			draw_pixel(meta->img, (*line)[i]);
			i++;
		}
		iso_free(line);
		data = data->next;
		y++;
	}
}

void		iso(t_meta *meta)
{
	t_data	*data;
	t_px	**line;

	data = meta->data[meta->arg];
	if ((line = (t_px**)malloc(sizeof(t_px*) * 2)))
	{
		line[0] = NULL;
		if (meta->graph.x == 0)
			iso_loop(meta, data, line);
		else
			iso_pointed(meta, data, line);
		iso_free(line);
	}
}
