/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:41:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/27 05:56:12 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	main_getdata(t_data *data[], t_meta *meta, char **argv)
{
	int		i;

	i = 1;
	while (i < meta->arg)
	{
		if (!(data[i - 1] = parser(argv[i])))
			err_open(i);
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_meta	*meta;
	t_data	*data[argc - 1];

	meta = (t_meta*)malloc(sizeof(t_meta));

	if (argc > 1)
	{
		meta->mlx = mlx_init();
		meta->win = mlx_new_window(meta->mlx, 1000, 1000, "fdf");
		meta->arg = argc;
		
		meta->img = draw_new_img(meta->mlx, 1000, 1000);

		ft_putendl("recup donnees");
		main_getdata(data, meta, argv);

		ft_putendl("process iso");
		iso(meta, data[0]);
		
		ft_putendl("et maintenant affichage");
		mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
		
		mlx_loop(meta->mlx);
	}
	return (0);
}
