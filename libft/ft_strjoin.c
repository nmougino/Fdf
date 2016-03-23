/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 09:17:33 by nmougino          #+#    #+#             */
/*   Updated: 2016/02/24 20:16:33 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ans;
	int		len;

	len = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	ans = (char*)malloc(sizeof(char) * (len + 1));
	if (ans)
	{
		ft_strcpy(ans, s1);
		ft_strcat(ans, s2);
		return (ans);
	}
	return (NULL);
}
