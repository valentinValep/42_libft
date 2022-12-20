# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2022/12/20 23:15:12 by vlepille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = cc

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I.

BASE_FILE = base

SRC = $(BASE_FILE)/ft_isalnum.c \
	$(BASE_FILE)/ft_isalpha.c \
	$(BASE_FILE)/ft_isascii.c \
	$(BASE_FILE)/ft_isdigit.c \
	$(BASE_FILE)/ft_isprint.c \
	$(BASE_FILE)/ft_strlen.c \
	$(BASE_FILE)/ft_memset.c \
	$(BASE_FILE)/ft_bzero.c \
	$(BASE_FILE)/ft_memcpy.c \
	$(BASE_FILE)/ft_memmove.c \
	$(BASE_FILE)/ft_strlcpy.c \
	$(BASE_FILE)/ft_strlcat.c \
	$(BASE_FILE)/ft_toupper.c \
	$(BASE_FILE)/ft_tolower.c \
	$(BASE_FILE)/ft_strchr.c \
	$(BASE_FILE)/ft_strrchr.c \
	$(BASE_FILE)/ft_strncmp.c \
	$(BASE_FILE)/ft_memchr.c \
	$(BASE_FILE)/ft_memcmp.c \
	$(BASE_FILE)/ft_strnstr.c \
	$(BASE_FILE)/ft_atoi.c \
	$(BASE_FILE)/ft_calloc.c \
	$(BASE_FILE)/ft_strdup.c \
	$(BASE_FILE)/ft_substr.c \
	$(BASE_FILE)/ft_strjoin.c \
	$(BASE_FILE)/ft_strtrim.c \
	$(BASE_FILE)/ft_split.c \
	$(BASE_FILE)/ft_itoa.c \
	$(BASE_FILE)/ft_strmapi.c \
	$(BASE_FILE)/ft_striteri.c \
	$(BASE_FILE)/ft_putchar_fd.c \
	$(BASE_FILE)/ft_putstr_fd.c \
	$(BASE_FILE)/ft_putendl_fd.c \
	$(BASE_FILE)/ft_putnbr_fd.c

OBJ = ${SRC:.c=.o}

RM = rm -f

$(NAME) : $(OBJ)
	ar -rc $(NAME) $(OBJ)

%.o : %.c
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

all : $(NAME)

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all clean fclean re
