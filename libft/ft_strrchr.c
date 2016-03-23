/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 12:41:15 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/01 12:41:30 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ans;

	i = ft_strlen(s);
	ans = NULL;
	while ((s[i] != (char)c) && i >= 0)
		i--;
	if (s[i] == (char)c)
		ans = (char*)s + i;
	return (ans);
}
