# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdeltour <mdeltour@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/02 18:20:04 by mdeltour          #+#    #+#              #
#    Updated: 2019/05/27 15:46:03 by mdeltour         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
CC = gcc
CFLAGS = -g
SRC_PATH = ./
INC_PATH = ./
OBJ_PATH = ./obj/
LIB_PATH = ./

SRC_NAME = main.c\
		   fillit.c\
		   tool.c\
		   valid_file.c\
		   board.c\
		   solve_map.c
INC_NAME = fillit.h
OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
INC = $(addprefix -I, $(INC_PATH))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix $(LIB_PATH),$(LIB_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/ fclean && make -C libft/
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(INC) -I libft/ -L libft/ -lft
	echo "\r\033[32m ~~ FINISH ~~                              \033[0m"
$(OBJ_PATH)%.o: $(SRC_PATH)%.c $(INC_NAME) 
	printf "\033[34m\r"
	/bin/echo -n "[ MAKE IN PROGRESS ~ PLEASE WAIT ]"
	mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -I ./libft/ -o $@ -c $< 

clean:
	printf "\033[34m"
	/bin/echo -n "[ CLEAN IN PROGRESS ~ PLEASE WAIT ]"
	make -C ./libft clean
	rm -rf $(OBJ_PATH)
	echo "\r\033[36m ~ CLEAN FINISH ~                  "

fclean: clean
	make -C ./libft fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: all clean fclean re $(NAME) $(OBJ) $(SRC) $(INC) $(LIB)
