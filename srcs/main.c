/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:41:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/28 05:01:40 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_meta		*init_meta(int argc)
{
	t_meta	*meta;
	int		i;

	i = 0;
	meta = (t_meta*)ft_memalloc(sizeof(t_meta));
	if (meta)
	{
		meta->mlx = mlx_init();
		meta->win = mlx_new_window(meta->mlx, 1000, 1000, "fdf");
		meta->arg = argc;	
		meta->img = draw_new_img(meta->mlx, 1000, 1000);
		while (i < 127)
			meta->ktab[i++] = 0;
	}
	return (meta);
}

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

	meta = NULL;
	if (argc > 1)
	{
		meta = init_meta(argc);
		main_getdata(data, meta, argv);
		iso(meta, data[0]);
		mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
		//init_hooks(meta);
		mlx_loop(meta->mlx);
	}
	return (0);
}

/*
int	main()
{
	void	*mlx = mlx_init();
	void	*win = mlx_new_window(mlx, 1000, 1000, "wef");
	
	mlx_hook		- key press
	mlx_key_hook 	- key release
					- mouse press
					- mouse release
					- mouse move
	mlx_loop_hook	- iteration
	
	mlx_hook repetition

	structure
		tableau de bits nombre de touches possibles
		mlx_hook -> touche corres 1
		mlx_key_hook -> 0
	
	mlx_hook(win, 2, 0, keyswitch(keycode, param), param);
	mlx_key_hook(win, keyswitch(keycode, param), param);
	mlx_loop_hook(mlx, funct, void* param);


funct{
	if (tab[0])
		faire truc
	
	draw
}


	mlx_loop(mlx);
	return (0);
}
*/
