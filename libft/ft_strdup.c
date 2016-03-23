/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:05:28 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/03 17:03:17 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*ans;
	int		len;
	int		i;

	len = ft_strlen(s1);
	ans = (char*)malloc(sizeof(char) * (len + 1));
	i = 0;
	if (ans)
	{
		while (i < len)
		{
			ans[i] = s1[i];
			i++;
		}
		ans[i] = '\0';
	}
	return (ans);
}
