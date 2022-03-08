NAME		= libftprintf.a
SRC_PASS	= src/
OTHER_PASS	= other/
OBJS		= $(SRC:%.c=%.o)
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -I./
SUBMIT_42	= git@vogsphere-v2.42tokyo.jp:vogsphere/intra-uuid-788a2123-b5c8-4fa9-9089-297b49b2c9fa-4035245-blyu
SUBMIT_42d	= libftprintf_submit42_files
SUBMIT_d	= libftprintf_submit_files
TESTER		= https://github.com/Tripouille/printfTester.git

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
	mkdir $(SUBMIT_d)
	cp $(SRC_PASS)* $(SUBMIT_d)
	cp $(OTHER_PASS)* $(SUBMIT_d)
	mv $(SUBMIT_d) ../

submit42 : push outclean
	git clone $(SUBMIT_42) $(SUBMIT_42d)
	rm -f $(SUBMIT_42d)/*
	rm -rf $(SUBMIT_42d)/*
#	cp $(SRC) $(SUBMIT_42d)
	mv $(SUBMIT_42d) ../

clean :
	rm -f $(OBJS_b) $(OBJS)

fclean : clean
	rm -f $(NAME)
	rm -rf $(SUBMIT_d)

outclean :
	rm -rf ../$(SUBMIT_d)
	rm -rf ../$(SUBMIT_42d)

allclean : fclean outclean

re : fclean all
