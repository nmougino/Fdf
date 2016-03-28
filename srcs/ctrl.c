/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 01:51:23 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/28 09:49:15 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		kswitch(int kc, void *param)
{
	int 	u;
	t_meta	*meta;

	meta = (t_meta*)param;
	u = 0;
	if (kc < 0 || kc > 126)
		return (0);
	meta->ktab[kc] = meta->ktab[kc] == 1 ? 0 : 1;
	return (0);
}

int		ctrl_exe(void *param)
{
	t_meta	*meta;

	meta = (t_meta*)param;
	(meta->ktab[53] == 1 || meta->ktab[12] == 1) ? ctrl_exit(meta) : 0;
	//(meta->ktab[126] == 1) ? ctrl_trans_ud(meta, -1) : 0;
	//(meta->ktab[125] == 1) ? ctrl_trans_ud(meta, 1) : 0;
	//(meta->ktab[123] == 1) ? ctrl_trans_lr(meta, -1) : 0;
	//(meta->ktab[124] == 1) ? ctrl_trans_lr(meta, 1) : 0;
	//(meta->ktab[] == 1) ? ctrl_rotation(meta) : 0;
	//(meta->ktab[] == 1) ? ctrl_zoom(meta, 1) : 0;
	//(meta->ktab[] == 1) ? ctrl_zoom(meta, 0) : 0;
	//(meta->ktab[] == 1) ? ctrl_npfile(meta, 1) : 0; //next prev file
	//(meta->ktab[] == 1) ? ctrl_npfile(meta, 0) : 0;
	mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
	return (0);
}

void	init_hooks(t_meta *meta)
{
	mlx_hook(meta->win, 2, 3, kswitch, meta);
	mlx_key_hook(meta->win, kswitch, meta);
	mlx_loop_hook(meta->mlx, ctrl_exe, meta);
}
