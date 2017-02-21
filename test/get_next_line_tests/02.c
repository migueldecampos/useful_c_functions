/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 21:24:38 by mmatamou          #+#    #+#             */
/*   Updated: 2017/02/20 22:30:12 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_tests.h"

int		test_02(void)
{
	char	*line;
	int		fd;
	int		i;
	int		error;
	int		ret;

	print_log("Test02 - one line without \'\\n\' at the end\n");
	fd = open("02.txt", O_RDONLY);
	i = 0;
	error = 0;
	line = NULL;
	while ((((ret = get_next_line(fd, &line))) == 1) && (i < 10))
	{
		if ((i == 0) && (ft_strcmp(line, "abcdef") != 0))
			error = error + 1;
		i = i + 1;
	}
	close(fd);
	if (i != 1)
	{
		print_log("In Test02 should have returned 1 only once.\n");
		return (-1);
	}
	if (error != 0)
	{
		print_log("In Test02 should have read \"abcdef\".\n");
		return (-1);
	}
	print_log("Ok\n\n");
	return (0);
}
