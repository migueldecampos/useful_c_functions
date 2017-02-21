/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 23:19:08 by mmatamou          #+#    #+#             */
/*   Updated: 2017/02/20 23:19:12 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	print_log(char *str)
{
	static int	fd = -1;
	int			len;

	if (fd == -1)
		fd = open("log", O_RDWR | O_CREAT |  O_APPEND, 0777);
	len = 0;
	while (str[len])
		len++;
	write(fd, str, len);
}
