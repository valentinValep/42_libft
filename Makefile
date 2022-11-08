# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    MAKEFILE                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2022/10/21 02:24:43 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc

FLAGS = -Wall -Werror -Wextra

SRC = src/ft_isalnum.c \
	src/ft_isalpha.c \
	src/ft_isascii.c \
	src/ft_isdigit.c \
	src/ft_isprint.c \
	src/ft_isprint.c \
	src/ft_atoi.c \
	src/ft_strlen.c

OBJ = bin/ft_isalnum.o \
	bin/ft_isalpha.o \
	bin/ft_isascii.o \
	bin/ft_isdigit.o \
	src/ft_isprint.c \
	bin/ft_atoi.o \
	bin/ft_strlen.o

RM = rm -f

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

bin/%.o : src/%.c
	$(CC) $(FLAGS) -c $< -o $@

test.exe : $(NAME) test.c # @TODO RM
	$(CC) $(FLAGS) -g3 -o test.exe test.c $(NAME)

norminette : # @TODO RM
	py -m norminette src/

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean # @TODO RM -> $(RM) test.exe
	$(RM) $(NAME)
	$(RM) test.exe

re : fclean all

.PHONY: all clean fclean re norminette # @TODO rm norminette
