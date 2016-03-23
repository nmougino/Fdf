/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/22 21:54:45 by nmougino          #+#    #+#             */
/*   Updated: 2016/02/22 21:57:43 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strinc(char **ptr, int size, char c)
{
	char	*ans;
	int		i;

	ans = ft_strnew(size);
	i = 0;
	if (ans)
	{
		while (i < size)
		{
			ans[i] = (*ptr)[i];
			i++;
		}
		ans[i] = c;
		free(*ptr);
		*ptr = ans;
		return (1);
	}
	return (0);
}
