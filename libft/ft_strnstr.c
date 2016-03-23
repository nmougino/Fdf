/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 13:02:21 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/03 16:20:40 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s2);
	if (!(*s2))
		return ((char*)s1);
	while (*s1 && n-- >= len)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, len) == 0)
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}
