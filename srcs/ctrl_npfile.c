/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ctrlnpfile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:12:40 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/29 16:27:55 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

inline void	ctrl_npfile(t_meta *meta, int p)
{
	int	i;

	i = 0;
	while (meta->data[i++]);
	meta->arg += p;
	meta->arg == -1 ? meta->arg = i - 2 : 0;
	meta->arg == i - 1 ? meta->arg = 0 : 0;
}
