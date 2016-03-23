/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:29:24 by nmougino          #+#    #+#             */
/*   Updated: 2015/11/26 18:26:19 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int		count;
	int		count2;
	char	*ans;

	count = ft_strlen(str) - 1;
	count2 = 0;
	ans = (char*)malloc(sizeof(char) * (count + 2));
	while (count >= 0)
	{
		ans[count2] = str[count];
		count--;
		count2++;
	}
	ans[count2] = '\0';
	return (ans);
}
