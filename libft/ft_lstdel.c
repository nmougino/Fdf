/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:14:19 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/04 23:51:28 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*cur;
	t_list	*nxt;

	cur = *alst;
	while (cur)
	{
		nxt = cur->next;
		del(cur->content, cur->content_size);
		free(cur);
		cur = nxt;
	}
	*alst = NULL;
}
