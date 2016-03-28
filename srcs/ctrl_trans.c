/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrl_trans.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/28 10:40:27 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/28 10:46:52 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ctrl_trans_ud(t_meta *meta, int p)
{
	meta->pto.y += X0U * p;
}

void	ctrl_trans_lr(t_meta *meta, int p)
{
	meta->pto.x += X0U * p;
}
