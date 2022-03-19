# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: daisukeyamaguchi <daisukeyamaguchi@stud    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/21 20:54:49 by daisukeyama       #+#    #+#              #
#    Updated: 2022/03/17 00:47:11 by daisukeyama      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

SRCS := ft_isalpha.c ft_isascii.c ft_isalnum.c \
ft_isdigit.c ft_isprint.c ft_strchr.c ft_strlen.c \
ft_memcpy.c ft_toupper.c ft_tolower.c ft_strrchr.c ft_strncmp.c \
ft_strlcat.c ft_memset.c ft_bzero.c ft_memmove.c ft_strlcpy.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_strjoin.c ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_strtrim.c ft_substr.c ft_strmapi.c ft_split.c ft_striteri.c ft_itoa.c ft_countlength.c

OBJS := $(SRCS:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror
INCDIR := ../includes
AR := ar
ARFLAGS := rcs
RM := rm -f

.c.o:
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY: clean fclean re all


