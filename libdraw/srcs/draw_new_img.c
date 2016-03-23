/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_new_img.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 01:03:06 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/23 01:54:31 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libdraw.h"

t_img	*draw_new_img(void *mlx, int width, int height)
{
	t_img	*ans;

	ans = (t_img*)malloc(sizeof(t_img));
	if (!ans)
		return (NULL);
	ans->img = mlx_new_image(mlx, width, height);
	ans->width = width;
	ans->height = height;
	ans->data = mlx_get_data_addr(ans->img, &(ans->bpp), &(ans->size_line), &(ans->endian));
	return (ans);
}
