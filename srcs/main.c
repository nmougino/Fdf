/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:41:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/24 17:29:04 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	main_getdata(t_data *data[], t_meta *meta, char **argv)
{
	int		i;

	i = 1;
	while (i < meta->arg)
	{
		if (!(data[i] = parser(argv[i])))
			err_open(i);
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_meta	meta;
	t_data	*data[argc - 1];

	meta.mlx = mlx_init();
	meta.win = mlx_new_window(meta.mlx, 1000, 1000, "fdf");
	meta.arg = argc;

	main_getdata(data, &meta, argv);
	mlx_loop(meta.mlx);
	return (0);
}
