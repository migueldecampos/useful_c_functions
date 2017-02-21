# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmatamou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/11 19:54:53 by mmatamou          #+#    #+#              #
#    Updated: 2017/02/11 21:26:23 by mmatamou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libunit.a

CC		= gcc

FLAGS	= -Wall -Wextra -Werror

SRCS	= launcher.c load_test.c ft_putn.c ft_putc.c ft_puts.c log.c
OBJS	= $(addprefix $(OBJDIR), $(SRCS:.c=.o))

SRCDIR	= ./framework/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: full

full: obj $(NAME)

obj:
	mkdir $(OBJDIR)

$(OBJDIR)%.o: $(SRCDIR)%.c
	$(CC) $(FLAGS) -I $(INCDIR) -o $@ -c $<

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

test: re
	make -C ./real-tests re
	make -C ./real-tests test

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all full obj clean fclean re
