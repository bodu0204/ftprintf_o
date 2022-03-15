NAME		= libftprintf.a
SRC_PASS	= src/
OTHER_PASS	= other/
OBJS		= $(SRC:%.c=%.o)
SUBMIT_42	= git@vogsphere-v2.42tokyo.jp:vogsphere/intra-uuid-788a2123-b5c8-4fa9-9089-297b49b2c9fa-4035245-blyu
SUBMIT_42d	= libftprintf_submit42_files/
SUBMIT_d	= libftprintf_submit_files/
LIBFT_GIT	= https://github.com/bodu0204/libft_o.git
LIBFT_o		= libft_o/
LIBFT_d		= libft/
TESTER		= https://github.com/Tripouille/printfTester.git

all : $(NAME)

$(NAME) : submitfile
	cd "$(PWD)/$(SUBMIT_d)" && make all
	mv $(SUBMIT_d)$(NAME) ./

push : fclean
	git add .
	git commit --allow-empty -m "commit form makefile"
	git push

clonelibft :
	git clone $(LIBFT_GIT) $(LIBFT_o)
	cd "$(PWD)/$(LIBFT_o)" && make submit
	rm -rf $(LIBFT_o)

submitfile : push clonelibft
	mkdir $(SUBMIT_d)
	cp $(SRC_PASS)* $(SUBMIT_d)
	cp $(OTHER_PASS)* $(SUBMIT_d)
	mv $(LIBFT_d) $(SUBMIT_d)

submit : outclean submitfile
	mv $(SUBMIT_d) ../

submit42 : push outclean submitfile
	git clone $(SUBMIT_42) $(SUBMIT_42d)
	rm -f $(SUBMIT_42d)/*
	rm -rf $(SUBMIT_42d)/*
	cp $(SUBMIT_d)* $(SUBMIT_42d)
	rm -rf $(SUBMIT_d)
	cd "$(PWD)/$(SUBMIT_42d)" && make push
	mv $(SUBMIT_42d) ../

fclean :
	rm -f $(NAME)
	rm -rf $(SUBMIT_d)
	rm -rf $(SUBMIT_42d)
	rm -rf $(LIBFT_d)

outclean :
	rm -rf ../$(SUBMIT_d)
	rm -rf ../$(SUBMIT_42d)

allclean : fclean outclean

re : fclean all
