/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:36:19 by mmatamou          #+#    #+#             */
/*   Updated: 2017/02/20 22:20:28 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libunit.h"

static int	printer_stats(int success, int total)
{
	ft_puts("\e[1;38;5;14m");
	ft_putn(success);
	ft_putc('/');
	ft_putn(total);
	ft_putc('\n');
	if (success < total)
		return (-1);
	return (0);
}

static int	stats(t_unit_test *list)
{
	int success;
	int total;

	while (list->prev != NULL)
		list = list->prev;
	success = 0;
	total = 0;
	while (list != NULL)
	{
		if (list->ok != 0)
			success = success + 1;
		total = total + 1;
		if (list->prev != NULL)
			free(list->prev);
		if (list->next == NULL)
		{
			free(list);
			list = NULL;
		}
		else
			list = list->next;
	}
	return (printer_stats(success, total));
}

static void	printer_launch(char *name, char *state)
{
	ft_puts("\e[1;38;5;11m   > ");
	ft_puts(name);
	ft_puts("\e[0m : [");
	ft_puts(state);
	ft_puts("\e[0m]\n");
}

static void	rec(t_unit_test *tests, int status)
{
	if (WIFSIGNALED(status) != 0)
	{
		if (WTERMSIG(status) == 11)
			printer_launch(tests->test_name, "\e[1;38;5;9mSEGV");
		if (WTERMSIG(status) == 10)
			printer_launch(tests->test_name, "\e[1;38;5;5mBUSE");
	}
	if (WIFEXITED(status) != 0)
		if (WEXITSTATUS(status) == 0)
			tests->ok = tests->ok + 1;
//	else if (tests->test_function() == 0)
//		tests->ok = tests->ok + 1;
}

int			launch_tests(t_unit_test *tests)
{
	pid_t	x;
	int		status;
	int		out;

	if (tests == NULL)
		return (0);
	x = fork();
	out = 0;
	if (x == 0)
	{
		if (tests->test_function() == -1)
			printer_launch(tests->test_name, "\e[1;38;5;1mKO");
		else
			printer_launch(tests->test_name, "\e[1;38;5;10mOK");
		exit(0);
	}
	if (x > 0)
	{
		wait(&status);
		rec(tests, status);
		launch_tests(tests->next);
		if (tests->next == NULL)
			out = stats(tests);
	}
	return (out);
}
