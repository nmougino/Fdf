/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 00:17:33 by nmougino          #+#    #+#             */
/*   Updated: 2016/03/24 17:44:45 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	datafree(t_data **fst)
{
	t_data	*cur;
	t_data	*nxt;

	cur = *fst;
	while (cur)
	{
		nxt = cur->next;
		free(cur->data);
		free(cur);
		cur = cur->next;
	}
	*fst = NULL;
}
