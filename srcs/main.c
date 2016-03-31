/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 21:41:13 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/31 15:13:31 by nmougino         ###   ########.fr       */
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
		init_hooks(meta);
		mlx_loop(meta->mlx);
	}
	else
		err_input();
	return (0);
}
