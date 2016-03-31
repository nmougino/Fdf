/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrlnpfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:12:40 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/31 17:35:20 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline void	ctrl_npfile(t_meta *meta, int p)
{
	int	i;

	i = meta->argc;
	meta->arg += p;
	meta->arg == -1 ? meta->arg = i - 1 : 0;
	meta->arg == i ? meta->arg = 0 : 0;
	meta->pto.x = X0;
	meta->pto.y = Y0;
	if (!meta->data[meta->arg])
		ctrl_npfile(meta, (p == 0) ? 1 : p);
}
