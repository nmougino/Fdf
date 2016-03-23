/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 05:18:04 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/02 04:48:51 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*ans;

	i = 0;
	ans = NULL;
	while ((s[i] != (char)c) && s[i])
		i++;
	if (s[i] == (char)c)
		ans = (char*)s + i;
	return (ans);
}
