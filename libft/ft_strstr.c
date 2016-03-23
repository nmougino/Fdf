/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:26:40 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/01 13:31:42 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	str = (char*)s1;
	if (!(s2[i]))
		return (str);
	while (s1[i])
	{
		j = 0;
		while (s2[j] == s1[i + j] && s2[j])
			j++;
		if (s2[j] == '\0')
			return (&(str[i]));
		i++;
	}
	return (NULL);
}
