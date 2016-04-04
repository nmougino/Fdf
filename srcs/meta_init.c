/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 09:54:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/04/05 00:27:26 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		getdata(t_meta *meta, t_data **data, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if ((data[i - 1] = parser(argv[i])))
		{
			meta->istheredata = 1;
			meta->datamax[i - 1] = data_getmax(data[i - 1]);
		}
		i++;
	}
	data[i - 1] = NULL;
}

void			meta_reset(t_meta *meta)
{
	meta->pto.x = WINX / 2;
	meta->pto.y = WINY / 2;
	meta->pta.x = XA;
	meta->pta.y = YA;
	meta->ptaa.x = 1;
	meta->ptaa.y = 1;
	meta->graph.x = 0;
	meta->graph.y = 0;
	meta->coefz = ZA;
	meta->angle = 270;
	ctrl_rot(meta, 0);
	meta->zaa = YA / 2;
}

t_meta			*meta_init(int argc, char **argv)
{
	t_meta	*meta;
	int		i;

	i = 0;
	if ((meta = (t_meta*)ft_memalloc(sizeof(t_meta))) &&
			(meta->data = (t_data**)ft_memalloc(sizeof(t_data*) * argc)) &&
			(meta->datamax = (t_px*)ft_memalloc(sizeof(t_px) * argc)))
	{
		meta->istheredata = 0;
		getdata(meta, meta->data, argc, argv);
		meta->mlx = mlx_init();
		meta->win = mlx_new_window(meta->mlx, WINX, WINY, "fdf");
		meta->img = draw_new_img(meta->mlx, WINX, WINY);
		meta->arg = 0;
		meta_reset(meta);
		meta->argc = argc;
		while (i < 127)
			meta->ktab[i++] = 0;
	}
	return (meta);
}
