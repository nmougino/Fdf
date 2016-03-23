/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 03:56:35 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/07 20:05:44 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		ans;

	i = 0;
	ans = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n)
		i++;
	if ((s1[i] != s2[i]) && i < n)
		ans = (unsigned char)(s1[i]) - (unsigned char)(s2[i]);
	return (ans);
}
