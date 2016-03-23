/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 22:56:21 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/07 23:01:40 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nb, int pow)
{
	int		ans;

	ans = 1;
	if (nb == 1)
		ans = 1;
	else if (pow == 1)
		ans = nb;
	else if (pow == 0)
		ans = 1;
	else
		ans = ans * nb * ft_pow(nb, pow - 1);
	return (ans);
}
