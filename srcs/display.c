/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/27 03:04:03 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/27 03:11:17 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	disp_hor(t_img *img, t_pix *ptr)
{
	int	i;

	i = 0
	while (ptr[i] && ptr[i + 1])
		draw_line(img, ptr + i, ptr + 1 + i++);
}

void	disp_ver(t_meta *img, t_pix *cur, t_pix *prev)
{
	int	i;
	
	i = 0;
	while (cur[i] && prev[i])
		draw_line(img, cur + i, prev + i++);
}
