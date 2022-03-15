PROJECT_NAME	= libftprintf
NAME			= $(PROJECT_NAME).a
NAME_h			= $(PROJECT_NAME).h
SRC_PASS		= src/
SRCb_PASS		= src_bonus/
OTHER_PASS		= other/
OBJS			= $(SRC:%.c=%.o)
SUBMIT_42		= git@vogsphere-v2.42tokyo.jp:vogsphere/intra-uuid-788a2123-b5c8-4fa9-9089-297b49b2c9fa-4035245-blyu
SUBMIT_42d		= submit_to_42/
SUBMIT_d		= $(PROJECT_NAME)
LIBFT_GIT		= https://github.com/bodu0204/libft_o.git
LIBFT_od		= libft_o/
LIBFT_d			= libft/
TESTER_PASS		= tester/
TESTER_0		= test.c
TEST0			= test_case_0.a
TESTER_1_GIT	= https://github.com/Tripouille/printfTester.git
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -I./

all : $(NAME)

$(NAME) : submitfile
	cd "$(PWD)/$(SUBMIT_d)" && make all
	mv $(SUBMIT_d)$(NAME) ./
	mv $(SUBMIT_d)$(NAME_h) ./

bonus : submitfile
	cd "$(PWD)/$(SUBMIT_d)" && make bonus
	mv $(SUBMIT_d)$(NAME) ./
	mv $(SUBMIT_d)$(NAME_h) ./

push : fclean
	git add .
	git commit --allow-empty -m "commit form makefile"
	git push

clonelibft :
	git clone $(LIBFT_GIT) $(LIBFT_od)
	cd "$(PWD)/$(LIBFT_od)" && make submit
	rm -rf $(LIBFT_od)

submitfile : push clonelibft
	mkdir $(SUBMIT_d)
	cp $(SRC_PASS)* $(SUBMIT_d)
	cp $(SRCb_PASS)* $(SUBMIT_d)
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
	mv $(SUBMIT_42d) $(SUBMIT_d)
	mv $(SUBMIT_d) ../

test0 : bonus
	cp $(TESTER_PASS)$(TESTER_0) ./
	$(CC)$(CFLAGS) $(TESTER_0) $(NAME) -o $(test_case_0.a)
	rm -f $(TESTER_0)

fclean :
	rm -f $(NAME)
	rm -rf $(SUBMIT_d)
	rm -rf $(SUBMIT_42d)
	rm -rf $(LIBFT_d)

outclean :
	rm -rf ../$(SUBMIT_d)

allclean : fclean outclean

re : fclean all
