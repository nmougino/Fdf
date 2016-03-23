/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 07:42:21 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/14 23:26:08 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	int				len;
	char			*ans;

	i = 0;
	len = 0;
	ans = NULL;
	len = ft_strlen(s);
	ans = (char*)malloc(sizeof(char) * len + 1);
	if (ans)
	{
		while (s[i])
		{
			ans[i] = f(i, s[i]);
			i++;
		}
		ans[i] = '\0';
	}
	return (ans);
}
