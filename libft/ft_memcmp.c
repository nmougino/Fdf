/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 03:53:53 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/05 01:08:33 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sa;
	unsigned char	*sb;

	sa = (unsigned char*)s1;
	sb = (unsigned char*)s2;
	while (n--)
	{
		if (*sa != *sb)
			return (*sa - *sb);
		sa++;
		sb++;
	}
	return (0);
}
