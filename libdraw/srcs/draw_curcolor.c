/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_curcolor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:23:51 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 19:31:54 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libdraw.h"

float	draw_line_curcolor(t_line line, t_px cur)
{
	float	ans;

	ans = (float)((((ft_abs(line.dst.x - cur.x)
		+ ft_abs(line.dst.y - cur.y)) * line.src.color)
		+ ((ft_abs(line.src.x - cur.x)
		+ ft_abs(line.src.y - cur.y)) * line.dst.color)))
		/ (float)(line.dx + line.dy);
	while (ans > 0)
		ans -= 1;
	while (ans < 0)
		ans += 1;
	return (ans);
}
