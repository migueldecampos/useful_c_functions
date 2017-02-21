/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_launcher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/20 20:09:14 by mmatamou          #+#    #+#             */
/*   Updated: 2017/02/20 21:54:38 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl_tests.h"

int		gnl_test_launcher(void)
{
	t_unit_test	*testlist;

	testlist = 0;
	ft_puts("\e[1;38;5;13mGET_NEXT_LINE:\n");
	load_test(&testlist, "Test 01", &test_01);
	load_test(&testlist, "Test 02", &test_02);
	load_test(&testlist, "Test 03", &test_03);
	load_test(&testlist, "Test 04", &test_04);
	return (launch_tests(testlist));
}
