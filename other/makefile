NAME		= libftprintf.a
SRC			= ft_printf.c itos.c output.c set.c
HEADER		= ft_printf.h
SRC_b		= ft_printf_bonus.c itos_bonus.c output_bonus.c set_bonus.c
HEADER_b	= ft_printf_bonus.h
OBJS		= $(SRC:%.c=%.o)
OBJS_b		= $(SRC_b:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I./
SUBMIT_d	= libftprintf_submit_files
LIBFT_GIT	= https://github.com/bodu0204/libft_o.git
LIBFT_od	= libft_o/
LIBFT_d		= libft/
LIBFT_a		= libft.a
LIBFT_h		= libft.h
PRINTF_a	= printf.a

all : $(NAME)

$(NAME) : genlibft $(OBJS) $(HEADER)
	ar rs $(NAME) $(OBJS) $(LIBFT_d)*.o

bonus : genlibft $(OBJS_b) $(HEADER_b)
	ar rs $(NAME) $(OBJS_b) $(LIBFT_d)*.o

.c.o : $(SRC) $(SRC_b)
	$(CC) $(CFLAGS) -c $^

newlibft :
	rm -rf $(LIBFT_d)
	git clone $(LIBFT_GIT) $(LIBFT_od)
	cd "$(PWD)/$(LIBFT_od)" && make submit
	rm -rf $(LIBFT_od)

genlibft :
	cd "$(PWD)/$(LIBFT_d)" && make all
	cp $(LIBFT_d)$(LIBFT_h) ./

push : fclean
	git add .
	git commit --allow-empty -m "commit form makefile"
	git push

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)
	rm -rf $(SUBMIT_d)
	rm -rf $(LIBFT_d)

outclean :
	rm -rf ../$(SUBMIT_d)

allclean : fclean outclean

re : fclean all
