/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meta_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 09:54:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/28 23:02:27 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		getdata(t_data **data, int argc, char **argv)
{
	int		i;

	i = 1;
	while (i < argc)
	{
		if (!(data[i - 1] = parser(argv[i])))
			err_open(i);
		i++;
	}
	data[i - 1] = NULL;
}

t_meta			*meta_init(int argc, char **argv)
{
	t_meta	*meta;
	t_data	**data;
	int		i;

	i = 0;
	if ((meta = (t_meta*)ft_memalloc(sizeof(t_meta))) &&
			(data = (t_data**)ft_memalloc(sizeof(t_data*) * argc)))
	{
		getdata(data, argc, argv);
		meta->mlx = mlx_init();
		meta->win = mlx_new_window(meta->mlx, WINX, WINY, "fdf");
		meta->img = draw_new_img(meta->mlx, WINX, WINY);
		meta->data = data;
		meta->arg = 0;
		meta->pto.x = X0;
		meta->pto.y = Y0;
		meta->pta.x = XA;
		meta->pta.y = YA;
		meta->ptaa.x = 1;
		meta->ptaa.y = 1;

		meta->coefz = ZA;

		while (i < 127)
			meta->ktab[i++] = 0;
	}
	return (meta);
}
