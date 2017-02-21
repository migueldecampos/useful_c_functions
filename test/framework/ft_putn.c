/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 16:13:05 by mmatamou          #+#    #+#             */
/*   Updated: 2017/02/11 20:14:43 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int		ft_len(int n)
{
	int m;

	m = 10;
	if ((n > 999999999) || (n < -999999999))
		m = 10000000;
	while (((n / m) >= 10) || ((n / m) <= -10))
		m = m * 10;
	if ((n > -10) && (n < 10))
		m = 1;
	return (m);
}

static void		ft_print(int n, int m)
{
	int dig;
	int nb;

	nb = n;
	if (n < 0)
		ft_putc('-');
	while (m >= 1)
	{
		dig = nb / m;
		if (dig < 0)
			dig = -dig;
		nb = nb % m;
		m = m / 10;
		ft_putc(dig + 48);
	}
}

void			ft_putn(int n)
{
	int m;

	m = ft_len(n);
	ft_print(n, m);
}
