/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_new_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 17:16:46 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 17:49:06 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

t_line	draw_new_line(t_px *src, t_px *dst)
{
	t_line	ans;

	ans.src = *src;
	ans.dst = *dst;
	ans.dx = ft_abs(ans.dst.x - ans.src.x);
	ans.dy = ft_abs(ans.dst.y - ans.src.y);
	return (ans);
}
