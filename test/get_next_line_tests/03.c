/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:39:10 by mmatamou          #+#    #+#             */
/*   Updated: 2017/02/20 22:33:20 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_tests.h"

int		test_03(void)
{
	char	*line;
	int		fd;
	int		i;
	int		error;
	int		ret;

	print_log("Test03 - two lines\n");
	fd = open("03.txt", O_RDONLY);
	i = 0;
	error = 0;
	line = NULL;
	while ((((ret = get_next_line(fd, &line))) == 1) && (i < 10))
	{
		if ((i == 0) && (ft_strcmp(line, "Hello mate") != 0))
			error = error + 1;
		if ((i == 1) && (ft_strcmp(line, "How are you doing?") != 0))
			error = error + 1;
		i = i + 1;
	}
	close(fd);
	if (i != 2)
	{
		print_log("In Test02 should have returned 1 twice.\n");
		return (-1);
	}
	if (error != 0)
	{
		print_log("In Test02 should have read \"Hello mate\" and then \"How are you doing?\".\n");
		return (-1);
	}
	print_log("Ok\n\n");
	return (0);
}
