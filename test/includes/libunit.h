/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libunit.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 17:16:34 by mmatamou          #+#    #+#             */
/*   Updated: 2017/02/11 17:25:50 by mmatamou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBUNIT_H

# define LIBUNIT_H

# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct			s_unit_test
{
	char				*test_name;
	int					(*test_function)(void);
	struct s_unit_test	*next;
	struct s_unit_test	*prev;
	int					nbr;
	char				ok;
}						t_unit_test;

void					ft_putn(int n);
void					ft_puts(const char *s);
void					ft_putc(char c);
int						ft_streq(char const *s1, char const *s2);
int						launch_tests(t_unit_test *tests);
void					load_test(t_unit_test **list, char *name,
	int (*function)(void));
void					print_log(char *str);

#endif
