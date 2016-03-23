/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 07:27:08 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/14 23:25:45 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*ans;

	i = 0;
	len = 0;
	ans = NULL;
	len = ft_strlen(s);
	ans = (char*)malloc(sizeof(char) * len + 1);
	if (ans)
	{
		while (s[i])
		{
			ans[i] = f(s[i]);
			i++;
		}
		ans[i] = '\0';
	}
	return (ans);
}
