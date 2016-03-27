/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 03:25:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/27 05:56:14 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

static void	iso_free(t_px *ptr)
{
	if (ptr != NULL)
		free(ptr);
}

static t_px	iso_getcurp(t_data *data, size_t x, int y)
{
	t_px	curp;
	int		z;

	z = data->data[x];
	curp.x = X0 + (XA * x) + (XA * y) + (ZA * z);
	curp.y = Y0 + (-YA * x) + (YA * y) + (-ZA * z);
	curp.color = 0.333 - ((float)z / 100);
	return (curp);
}

void		iso(t_meta *meta, t_data *data)
{
	t_px	**line;
	int		y;
	size_t	i;
	size_t	prevsize;

	y = 0;
	i = 0;
	prevsize = 0;
	if ((line = (t_px**)malloc(sizeof(t_px*) * 2)))
	{
		line[0] = NULL;
		while (data && ((line[1] = (t_px*)malloc(sizeof(t_px) * (data->size + 1)))))
		{
			i = 0;
			while (i < data->size)
			{
				line[1][i] = iso_getcurp(data, i, y);
				printf("x: %d, y: %d, h: %f\n", line[1][i].x, line[1][i].y, line[1][i].color);
				if (i > 0)
					draw_line(meta->img, line[1] + i, line[1] + i - 1);
				if (i < prevsize)
					draw_line(meta->img, line[1] + i, line[0] + i);
				i++;
			}
			iso_free(line[0]);
			line[0] = line[1];
			prevsize = data->size;
			data = data->next;
			y++;
		}
		iso_free(line[0]);
	}
}
