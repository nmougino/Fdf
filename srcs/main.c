/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:41:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/28 09:55:18 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int argc, char **argv)
{
	t_meta	*meta;

	meta = NULL;
	if (argc > 1)
	{
		meta = meta_init(argc, argv);
		iso(meta);
		mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
		init_hooks(meta);
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
