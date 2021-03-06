/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 15:12:36 by mmatamou          #+#    #+#             */
/*   Updated: 2017/02/11 20:08:36 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void		ft_puts(char const *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i = i + 1;
	write(1, s, i);
}
