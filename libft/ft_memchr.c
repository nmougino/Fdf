/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 22:06:19 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/03 16:46:28 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ans;

	ans = (unsigned char*)s;
	while (n--)
	{
		if (*ans == (unsigned char)c)
			return (ans);
		ans++;
	}
	return (NULL);
}
