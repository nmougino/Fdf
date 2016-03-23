/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 16:23:37 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/07 22:52:37 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_itoa_doit(char *ans, int len, int nb)
{
	int	i;

	i = 0;
	ans[len] = '\0';
	if (nb < 0)
	{
		ans[i] = '-';
		nb *= -1;
		i++;
	}
	len--;
	while (i <= len)
	{
		ans[len] = (nb % 10) + '0';
		nb /= 10;
		len--;
	}
}

static char	*ft_minint(void)
{
	char	*ans;

	ans = (char*)malloc(12);
	if (ans)
	{
		ans[0] = '-';
		ans[1] = '2';
		ans[2] = '1';
		ans[3] = '4';
		ans[4] = '7';
		ans[5] = '4';
		ans[6] = '8';
		ans[7] = '3';
		ans[8] = '6';
		ans[9] = '4';
		ans[10] = '8';
		ans[11] = '\0';
	}
	else
		ans = NULL;
	return (ans);
}

char		*ft_itoa(int nb)
{
	char	*ans;
	int		len;

	ans = NULL;
	len = 0;
	if (nb == -2147483648)
	{
		ans = ft_minint();
	}
	else
	{
		len = ft_nbrlen(nb);
		ans = (char*)malloc((sizeof(char)) * (len + 1));
		if (ans)
		{
			ft_itoa_doit(ans, len, nb);
		}
	}
	return (ans);
}
