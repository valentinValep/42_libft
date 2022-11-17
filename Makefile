# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2022/11/17 17:16:39 by vlepille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I.

SRC = src/ft_isalnum.c \
	src/ft_isalpha.c \
	src/ft_isascii.c \
	src/ft_isdigit.c \
	src/ft_isprint.c \
	src/ft_strlen.c \
	src/ft_memset.c \
	src/ft_bzero.c \
	src/ft_memcpy.c \
	src/ft_memmove.c \
	src/ft_strlcpy.c \
	src/ft_strlcat.c \
	src/ft_toupper.c \
	src/ft_tolower.c \
	src/ft_strchr.c \
	src/ft_strrchr.c \
	src/ft_strncmp.c \
	src/ft_memchr.c \
	src/ft_memcmp.c \
	src/ft_strnstr.c \
	src/ft_atoi.c \
	src/ft_calloc.c \
	src/ft_strdup.c \
	src/ft_substr.c \
	src/ft_strjoin.c \
	src/ft_strtrim.c \
	src/ft_split.c \
	src/ft_itoa.c \
	src/ft_strmapi.c \
	src/ft_striteri.c \
	src/ft_putchar_fd.c \
	src/ft_putstr_fd.c \
	src/ft_putendl_fd.c \
	src/ft_putnbr_fd.c

#BONUS_SRC = src/ft_lstnew.c \
#	src/ft_lstadd_front.c \
#	src/ft_lstsize.c \
#	src/ft_lstlast.c \
#	src/ft_lstadd_back.c \
#	src/ft_lstdelone.c \
#	src/ft_lstclear.c \
#	src/ft_lstiter.c \
#	src/ft_lstmap.c

OBJ = bin/ft_isalnum.o \
	bin/ft_isalpha.o \
	bin/ft_isascii.o \
	bin/ft_isdigit.o \
	bin/ft_isprint.o \
	bin/ft_strlen.o \
	bin/ft_memset.o \
	bin/ft_bzero.o \
	bin/ft_memcpy.o \
	bin/ft_memmove.o \
	bin/ft_strlcpy.o \
	bin/ft_strlcat.o \
	bin/ft_toupper.o \
	bin/ft_tolower.o \
	bin/ft_strchr.o \
	bin/ft_strrchr.o \
	bin/ft_strncmp.o \
	bin/ft_memchr.o \
	bin/ft_memcmp.o \
	bin/ft_strnstr.o \
	bin/ft_atoi.o \
	bin/ft_calloc.o \
	bin/ft_strdup.o \
	bin/ft_substr.o \
	bin/ft_strjoin.o \
	bin/ft_strtrim.o \
	bin/ft_split.o \
	bin/ft_itoa.o \
	bin/ft_strmapi.o \
	bin/ft_striteri.o \
	bin/ft_putchar_fd.o \
	bin/ft_putstr_fd.o \
	bin/ft_putendl_fd.o \
	bin/ft_putnbr_fd.o

#BONUS_OBJ = bin/ft_lstnew.o \
#	bin/ft_lstadd_front.o \
#	bin/ft_lstsize.o \
#	bin/ft_lstlast.o \
#	bin/ft_lstadd_back.o \
#	bin/ft_lstdelone.o \
#	bin/ft_lstclear.o \
#	bin/ft_lstiter.o \
#	bin/ft_lstmap.o

RM = rm -f

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

# @TODO CALL $(NAME) ?? Ask Yanis
# @TODO MAKE BONUS :p
#bonus : $(NAME)
#	ar -rc $(NAME) $(BONUS_OBJ)

bin/%.o : src/%.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

test : $(NAME) test.c # @TODO RM
	$(CC) $(FLAGS) -g3 -o test.exe test.c $(NAME) -lbsd

nor : # @TODO RM
	norminette src/

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean # @TODO RM -> $(RM) test.exe
	$(RM) $(NAME)
	$(RM) test.exe test_put

re : fclean all

.PHONY: all clean fclean re norminette # @TODO rm norminette
