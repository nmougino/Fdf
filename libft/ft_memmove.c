/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 21:16:55 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/15 18:45:03 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	if (src < dst)
		while (i--)
			*((unsigned char*)(dst + i)) = *((unsigned char*)(src + i));
	else
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char*)(dst + i)) = *((unsigned char*)(src + i));
			i++;
		}
	}
	return (dst);
}
