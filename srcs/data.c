/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <nmougino@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/08 00:17:33 by nmougino          #+#    #+#             */
/*   Updated: 2016/04/04 23:16:45 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_px	data_getmax(t_data *data)
{
	t_px	ans;
	int		x;

	x = 0;
	ans.x = 0;
	ans.y = 0;
	while (data)
	{
		x = 0;
		while (x < data->size)
		{
			if (x > ans.x)
				ans.x = x;
			x++;
		}
		data = data->next;
		ans.y++;
	}
	ft_putnbrendl(ans.x);
	ft_putnbrendl(ans.y);
	return (ans);
}
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
