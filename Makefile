# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2022/12/20 23:57:20 by vlepille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := cc

FLAGS := -Wall -Werror -Wextra

INCLUDES := -I.

include base/Makefile
BASE_SRC := $(addprefix base/, $(SRC))
include str/Makefile
STR_SRC := $(addprefix str/, $(SRC))
include get_next_line/Makefile
GNL_SRC := $(addprefix get_next_line/, $(SRC))
include ft_printf/Makefile
PRINTF_SRC := $(addprefix ft_printf/, $(SRC))

SRC := $(BASE_SRC) $(STR_SRC) $(GNL_SRC) $(PRINTF_SRC)

OBJ := ${SRC:.c=.o}

RM := rm -f

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
