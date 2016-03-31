/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 01:51:23 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/31 02:08:55 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	kon(int kc, void *param)
{
	int 	u;
	t_meta	*meta;

	meta = (t_meta*)param;
	u = 0;
	(kc == K_ESC || kc == K_Q) ? ctrl_exit(meta) : 0;
	if (kc == K_CHEVD)
		ctrl_npfile(meta, 1);
	else if (kc == K_CHEVG)
		ctrl_npfile(meta, -1);
	else if (kc == K_P)
		meta->graph.x = (meta->graph.x == 0) ? 1 : 0;
	else if (kc == K_C)
		meta->graph.y = (meta->graph.y == 0) ? 1 : 0;
	else if (kc < 0 || kc > 126)
		return (0);
	meta->ktab[kc] = 1;
	return (0);
}

static int	koff(int kc, void *param)
{
	int 	u;
	t_meta	*meta;

	meta = (t_meta*)param;
	u = 0;
	if (kc == K_SPA)
		meta_reset(meta);
	if (kc < 0 || kc > 126)
		return (0);
	meta->ktab[kc] = 0;
	return (0);
}

static int	ctrl_exe(void *param)
{
	t_meta	*meta;

	meta = (t_meta*)param;
	(meta->ktab[K_UP] == 1) ? ctrl_trans_ud(meta, 1) : 0;
	(meta->ktab[K_DO] == 1) ? ctrl_trans_ud(meta, -1) : 0;
	(meta->ktab[K_LE] == 1) ? ctrl_trans_lr(meta, 1) : 0;
	(meta->ktab[K_RI] == 1) ? ctrl_trans_lr(meta, -1) : 0;
	(meta->ktab[K_H] == 1 && meta->ktab[K_J] == 0) ? ctrl_hight(meta, 1) : 0;
	(meta->ktab[K_H] == 0 && meta->ktab[K_J] == 1) ? ctrl_hight(meta, -1) : 0;
	//(meta->ktab[] == 1) ? ctrl_zoomi(meta) : 0;
	//(meta->ktab[] == 1) ? ctrl_zoomo(meta) : 0;
	//(meta->ktab[47] == 1) ? ctrl_npfile(meta, 1) : 0; //next prev file
	//(meta->ktab[43] == 1) ? ctrl_npfile(meta, -1) : 0;
	draw_clear_img(meta->img);
	iso(meta);
	mlx_put_image_to_window(meta->mlx, meta->win, meta->img->img, 0, 0);
	mlx_string_put(meta->mlx, meta->win, 2, 2, 0x00FF00, meta->data[meta->arg]->file);
	return (0);
}

void		init_hooks(t_meta *meta)
{
	mlx_hook(meta->win, 2, 3, kon, meta);
	mlx_key_hook(meta->win, koff, meta);
	mlx_loop_hook(meta->mlx, ctrl_exe, meta);
}
