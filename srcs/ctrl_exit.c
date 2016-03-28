/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 05:45:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/28 08:07:46 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ctrl_exit(t_meta *meta)
{
	int	i;

	i = 0;
	free(meta->mlx);
	free(meta->win);
	free(meta->img->data);
	free(meta->img->img);
	free(meta->img);
	while (meta->data[i])
	{
		free(meta->data[i]->data);
		free(meta->data[i]->file);
		free(meta->data[i]);
		i++;
	}
	free(meta->data);
	exit(0);
}
