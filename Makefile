# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2023/08/24 17:42:11 by vlepille         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libft.a

CC := cc

FLAGS := -Wall -Werror -Wextra

BASE_FILE := base
STR_FILE := str
GNL_FILE := get_next_line
PRINTF_FILE := ft_printf
VECTOR_FILE := vector

INCLUDES := -I. -I$(BASE_FILE) -I$(STR_FILE) -I$(GNL_FILE) -I$(PRINTF_FILE) -I$(VECTOR_FILE)

include base/Makefile
BASE_OBJ := $(addprefix $(BASE_FILE)/, $(OBJ))
include str/Makefile
STR_OBJ := $(addprefix $(STR_FILE)/, $(OBJ))
include get_next_line/Makefile
GNL_OBJ := $(addprefix $(GNL_FILE)/, $(OBJ))
include ft_printf/Makefile
PRINTF_OBJ := $(addprefix $(PRINTF_FILE)/, $(OBJ))
include vector/Makefile
VECTOR_OBJ := $(addprefix $(VECTOR_FILE)/, $(OBJ))

OBJ := $(BASE_OBJ) $(STR_OBJ) $(GNL_OBJ) $(PRINTF_OBJ) $(VECTOR_OBJ)

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
