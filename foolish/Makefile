# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: blyu <blyu@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 17:47:53 by blyu              #+#    #+#              #
#    Updated: 2022/03/19 17:54:24 by blyu             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRC			= foolish_printf.c
HEADER		= mk_ft_printf.h
OBJS		= $(SRC:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

all : $(NAME)

$(NAME) :$(OBJS)
	ar rs $(NAME) $(OBJS) $(LIBFT_d)*.o

.c.o : $(SRC)
	$(CC) $(CFLAGS) -c $^

genlibft :
	cd "$(LIBFT_d)" && make bonus
	cp $(LIBFT_d)$(LIBFT_h) ./

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
