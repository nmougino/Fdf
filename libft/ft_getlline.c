/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getlinel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 04:51:05 by nmougino          #+#    #+#             */
/*   Updated: 2016/01/12 16:30:30 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getlline(char *buf, int l)
{
	char	*cur;
	char	*ans;
	int		i;

	i = 0;
	cur = ft_gotoline(buf, l);
	ans = ft_strnew(ft_getlinesize(cur) + 1);
	while (cur[i] && cur[i] != '\n')
	{
		ans[i] = cur[i];
		i++;
	}
	ans[i] = '\0';
	return (ans);
}
