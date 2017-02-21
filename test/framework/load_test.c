/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:02:15 by mmatamou          #+#    #+#             */
/*   Updated: 2017/02/11 22:52:07 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

void	load_test(t_unit_test **list, char *name, int (*function)(void))
{
	if (*list == NULL)
	{
		*list = (t_unit_test*)malloc(sizeof(t_unit_test));
		(*list)->prev = NULL;
		(*list)->nbr = 1;
	}
	else
	{
		while ((*list)->next != NULL)
			*list = (*list)->next;
		(*list)->next = (t_unit_test*)malloc(sizeof(t_unit_test));
		(*list)->next->prev = *list;
		*list = (*list)->next;
	}
	(*list)->next = NULL;
	(*list)->test_name = name;
	(*list)->test_function = function;
	(*list)->ok = 0;
	if ((*list)->prev != NULL)
		(*list)->nbr = ((*list)->prev)->nbr + 1;
	while ((*list)->prev != NULL)
		*list = (*list)->prev;
}
