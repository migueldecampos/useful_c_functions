# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/20 20:47:47 by mmatamou          #+#    #+#              #
#    Updated: 2017/02/20 22:43:36 by mmatamou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= gnl_tester

TEST_FILES	= main.c 00_launcher.c 01.c 02.c 03.c 04.c
TEST_FILES	+= 

SRCS		= $(TEST_FILES)
OBJS		= $(TEST_FILES:.c=.o)
INCS		= -I ../../libft -I ../includes
LIBFT		= ../../libft/libft.a
LIBUNIT		= ../libunit.a

CC			= gcc
FLAGS		= -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C ../../libft
	make -C ../
	$(CC) $(FLAGS) $(INCS) -c $(SRCS)
	$(CC) $(FLAGS) $(INCS) -o $(NAME) $(OBJS) $(LIBFT) $(LIBUNIT)

test: re
	./$(NAME)

clean:
	make -C ../../libft fclean
	make -C ../ fclean
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME) log

re: fclean $(NAME)
