# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/02 16:38:17 by daisukeyama       #+#    #+#              #
#    Updated: 2022/03/17 00:33:54 by daisukeyama      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
SRCDIR := ./srcs/
SRCS := ft_big10to16.c ft_print_ptr.c ft_printf.c \
ft_small10to16.c ft_u_itoa.c ft_countlength.c ft_printchars.c

SRCS := $(addprefix $(SRCDIR), $(SRCS))
OBJS := $(SRCS:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKE := make
INCDIR := ./includes
AR := ar
ARFLAGS := rcs
RM := rm -f

.c.o:
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all:			$(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean re all