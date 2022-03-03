NAME		= libftprintf.a
SRC			=
OBJS		= $(SRC:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I./
SUBMIT		= git@vogsphere-v2.42tokyo.jp:vogsphere/intra-uuid-788a2123-b5c8-4fa9-9089-297b49b2c9fa-4035245-blyu

all : $(NAME)

$(NAME) : $(OBJS)
	ar rs $(NAME) $^

.c.o : $(SRC)
	$(CC) $(CFLAGS) -c $^

push :
	git add .
	git commit -m "commit form makefile"
	git push

submit : push
	rm -rf ../$(OBJS)
	git clone $(OBJS)
	rm -rf $(OBJS)/*

clean :
	rm -f $(OBJS_b) $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all
