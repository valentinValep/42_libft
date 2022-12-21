# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2022/12/21 08:07:15 by vlepille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := cc

FLAGS := -Wall -Werror -Wextra

BASE_FILE := base
STR_FILE := str
GNL_FILE := get_next_line
PRINTF_FILE := ft_printf

INCLUDES := -I. -I$(BASE_FILE) -I$(STR_FILE) -I$(GNL_FILE) -I$(PRINTF_FILE)

include base/Makefile
BASE_SRC := $(addprefix $(BASE_FILE)/, $(SRC))
include str/Makefile
STR_SRC := $(addprefix $(STR_FILE)/, $(SRC))
include get_next_line/Makefile
GNL_SRC := $(addprefix $(GNL_FILE)/, $(SRC))
include ft_printf/Makefile
PRINTF_SRC := $(addprefix $(PRINTF_FILE)/, $(SRC))

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
