PROJECT_NAME= libftprintf
NAME		= $(PROJECT_NAME).a
SRC_PASS	= src/
OTHER_PASS	= other/
OBJS		= $(SRC:%.c=%.o)
SUBMIT_42	= git@vogsphere-v2.42tokyo.jp:vogsphere/intra-uuid-788a2123-b5c8-4fa9-9089-297b49b2c9fa-4035245-blyu
SUBMIT_42d	= submit_to_42/
SUBMIT_d	= libftprintf_submit_files/
LIBFT_GIT	= https://github.com/bodu0204/libft_o.git
LIBFT_o		= libft_o/
LIBFT_d		= libft/
TESTER		= https://github.com/Tripouille/printfTester.git

all : $(NAME)

$(NAME) : submitfile
	cd "$(PWD)/$(PROJECT_NAME)" && make all
	mv $(PROJECT_NAME)$(NAME) ./

push : fclean
	git add .
	git commit --allow-empty -m "commit form makefile"
	git push

clonelibft :
	git clone $(LIBFT_GIT) $(LIBFT_o)
	cd "$(PWD)/$(LIBFT_o)" && make submit
	rm -rf $(LIBFT_o)

submitfile : push clonelibft
	mkdir $(PROJECT_NAME)
	cp $(SRC_PASS)* $(PROJECT_NAME)
	cp $(OTHER_PASS)* $(PROJECT_NAME)
	mv $(LIBFT_d) $(PROJECT_NAME)

submit : outclean submitfile
	mv $(PROJECT_NAME) ../

submit42 : push outclean submitfile
	git clone $(SUBMIT_42) $(SUBMIT_42d)
	rm -f $(SUBMIT_42d)/*
	rm -rf $(SUBMIT_42d)/*
	cp $(PROJECT_NAME)* $(SUBMIT_42d)
	rm -rf $(PROJECT_NAME)
	cd "$(PWD)/$(SUBMIT_42d)" && make push
	mv $(SUBMIT_42d) $(PROJECT_NAME)
	mv $(PROJECT_NAME) ../

fclean :
	rm -f $(NAME)
	rm -rf $(PROJECT_NAME)
	rm -rf $(SUBMIT_42d)
	rm -rf $(LIBFT_d)

outclean :
	rm -rf ../$(PROJECT_NAME)

allclean : fclean outclean

re : fclean all
