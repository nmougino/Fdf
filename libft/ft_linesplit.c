/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linesplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/24 21:48:34 by nmougino          #+#    #+#             */
/*   Updated: 2016/02/26 01:20:32 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_linesplit(char *s, char c)
{
	char **ans;
	char *line;

	line = ft_getlline(s, 0);
	ans = ft_strsplit(line, c);
	free(line);
	return (ans);
}
