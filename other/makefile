NAME		= libftprintf.a
SRC			=
OBJS		= $(SRC:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I./
SUBMIT_d	= libftprintf_submit_files
LIBFT_GIT	= https://github.com/bodu0204/libft_o.git
LIBFT_d		= libft_o/

all : $(NAME)

$(NAME) : $(OBJS)
	ar rs $(NAME) $^

.c.o : $(SRC)
	$(CC) $(CFLAGS) -c $^

genlibft :
	git clone $(LIBFT_GIT) $(LIBFT_d)
	cd "$(PWD)/$(LIBFT_d)" && make all

push : fclean
	git add .
	git commit -m "commit form makefile"
	git push

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	rm -rf $(SUBMIT_d)

outclean :
	rm -rf ../$(SUBMIT_d)

allclean : fclean outclean

re : fclean all
