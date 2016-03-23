/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:33:42 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/14 23:40:28 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*ans;
	t_list	*tmp;
	t_list	*tmp2;

	tmp2 = f(lst);
	ans = ft_lstnew(tmp2->content, tmp2->content_size);
	if (ans)
		tmp = ans;
	lst = lst->next;
	while (lst)
	{
		tmp2 = f(lst);
		if (!(tmp->next = ft_lstnew(tmp2->content, tmp2->content_size)))
			return (NULL);
		tmp = tmp->next;
		lst = lst->next;
	}
	return (ans);
}
