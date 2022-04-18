# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ryoakira <ryoakira@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/16 17:47:53 by blyu              #+#    #+#              #
#    Updated: 2022/03/21 18:38:31 by ryoakira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a
SRC			= adjust.c ft_printf.c itos.c set.c tool.c
HEADER		= mk_ft_printf.h
SRC_b		= adjust_bonus.c ft_printf_bonus.c itos_bonus.c set_bonus.c tool_bonus.c
HEADER_b	= mk_ft_printf_bonus.h
OBJS		= $(SRC:%.c=%.o)
OBJS_b		= $(SRC_b:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I./
LIBFT_GIT	= https://github.com/bodu0204/libft_o.git
LIBFT_od	= libft_o/
LIBFT_d		= libft/
LIBFT_h		= libft.h
PRINTF_a	= printf.a

all : $(NAME)

$(NAME) : fclean genlibft $(OBJS) $(HEADER)
	ar rs $(NAME) $(OBJS) $(LIBFT_d)*.o

bonus : fclean genlibft $(OBJS_b) $(HEADER_b)
	ar rs $(NAME) $(OBJS_b) $(LIBFT_d)*.o

.c.o : $(SRC) $(SRC_b)
	$(CC) $(CFLAGS) -c $^

newlibft :
	rm -rf $(LIBFT_d)
	git clone $(LIBFT_GIT) $(LIBFT_od)
	cd "$(LIBFT_od)" && make submit
	rm -rf $(LIBFT_od)

genlibft :
	cd "$(LIBFT_d)" && make bonus
	cp $(LIBFT_d)$(LIBFT_h) ./

push : fclean
	git add .
	git commit --allow-empty -m "commit form makefile"
	git push

clean :
	rm -f $(OBJS) $(OBJS_b)
	cd "$(LIBFT_d)" && make clean

fclean : clean
	rm -f $(NAME)
	rm -f $(LIBFT_h)
	rm -rf $(LIBFT_od)
	cd "$(LIBFT_d)" && make fclean

re : fclean all
