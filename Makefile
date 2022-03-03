NAME		= libftprintf.a
SRC			=
OBJS		= $(SRC:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I./
SUBMIT		= git@vogsphere-v2.42tokyo.jp:vogsphere/intra-uuid-788a2123-b5c8-4fa9-9089-297b49b2c9fa-4035245-blyu
SUBMIT_d	= libftprintf_submit_files

all : $(NAME)

$(NAME) : $(OBJS)
	ar rs $(NAME) $^

.c.o : $(SRC)
	$(CC) $(CFLAGS) -c $^

push : fclean
	git add .
	git commit -m "commit form makefile"
	git push

submit : push outclean
	git clone $(SUBMIT) $(SUBMIT_d)
	rm -f $(SUBMIT_d)/*
	cp $(SRC) $(SUBMIT_d)
	mv $(SUBMIT_d) ../

clean :
	rm -f $(OBJS_b) $(OBJS)

fclean : clean
	rm -f $(NAME)
	rm -rf $(SUBMIT_d)

outclean :
	rm -rf ../$(SUBMIT_d)

allclean : fclean outclean

re : fclean all
