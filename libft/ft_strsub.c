/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:01:54 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/16 01:17:15 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ans;
	size_t	i;

	i = 0;
	ans = (char*)malloc(sizeof(char) * (len + 1));
	if (ans)
	{
		while (i < len)
		{
			ans[i] = s[start + i];
			i++;
		}
		ans[i] = '\0';
	}
	return (ans);
}
