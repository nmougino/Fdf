/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 01:51:23 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/28 06:58:24 by nmougino         ###   ########.fr       */
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
	meta->ktab[53] == 1 ? ctrl_exit(meta) : 0;
	return (0);
}

void	init_hooks(t_meta *meta)
{
	mlx_hook(meta->win, 2, 3, kswitch, meta);
	mlx_key_hook(meta->win, kswitch, meta);
	mlx_loop_hook(meta->mlx, ctrl_exe, meta);
}
