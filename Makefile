# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlepille <vlepille@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/21 02:24:43 by marvin            #+#    #+#              #
#    Updated: 2023/09/21 14:37:28 by vlepille         ###   ########.fr        #
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
MORE_FILE := more
FT_PRINTF_FD_FILE := ft_printf_fd

INCLUDES := -I. -I$(BASE_FILE) -I$(STR_FILE) -I$(GNL_FILE) -I$(PRINTF_FILE) -I$(VECTOR_FILE) -I$(MORE_FILE) -I$(FT_PRINTF_FD_FILE)

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
include more/Makefile
MORE_OBJ := $(addprefix $(MORE_FILE)/, $(OBJ))
include ft_printf_fd/Makefile
FT_PRINTF_FD_OBJ := $(addprefix $(FT_PRINTF_FD_FILE)/, $(OBJ))

OBJ := $(BASE_OBJ) $(STR_OBJ) $(GNL_OBJ) $(PRINTF_OBJ) $(VECTOR_OBJ) $(MORE_OBJ) $(FT_PRINTF_FD_OBJ)

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
