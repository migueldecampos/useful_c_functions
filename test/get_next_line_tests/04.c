/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:39:10 by mmatamou          #+#    #+#             */
/*   Updated: 2017/02/20 21:54:15 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_tests.h"

int		test_04(void)
{
	char	*line;
	int		fd;
	int		i;
	int		error;
	int		ret;

	print_log("Test04 - closed file descriptor\n");
	fd = open("04.txt", O_RDONLY);
	i = 0;
	error = 0;
	line = NULL;
	close(fd);
	ret = get_next_line(fd, &line);
	if (ret != -1)
	{
		print_log("Should have returned -1 when given a closed file descriptor\n");
		return (-1);
	}
	print_log("Ok\n\n");
	return (0);
}
