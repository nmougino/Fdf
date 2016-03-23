/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrendl.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmougino <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 01:54:54 by nmougino          #+#    #+#             */
/*   Updated: 2015/12/17 01:55:30 by nmougino         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbrendl(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else if (n == 2147483647)
		ft_putstr("2147483647");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n < 10)
			ft_putchar('0' + n);
		else
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
	}
	ft_putchar('\n');
}
