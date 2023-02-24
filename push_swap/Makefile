# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/19 21:21:36 by anolivei          #+#    #+#              #
#    Updated: 2023/01/24 13:43:27 by imisumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC_DIR = sources
OBJ_DIR = .objs

SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/push.c \
		$(SRC_DIR)/rotate.c \
		$(SRC_DIR)/reverse_rotate.c \
		$(SRC_DIR)/index.c \
		$(SRC_DIR)/new_node.c \
		$(SRC_DIR)/print.c \
		$(SRC_DIR)/small_stack.c \
		$(SRC_DIR)/big_stack.c \
		$(SRC_DIR)/swap.c \
		$(SRC_DIR)/group.c \
		$(SRC_DIR)/push_utils_1.c \
		$(SRC_DIR)/push_utils_2.c \
		$(SRC_DIR)/push_utils_3.c \
		$(SRC_DIR)/push_utils_4.c \
		$(SRC_DIR)/push_utils_5.c \
		$(SRC_DIR)/push_utils_500.c \
		$(SRC_DIR)/push_utils_501.c 

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC = clang
HEAD = -I./includes
CFLAGS = -g 
# -fsanitize=address
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ)
		@$(CC) $(OBJ) $(HEAD) $(CFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@

debug_mac: $(OBJ)
		@gcc $(HEAD) $(SRC) $(CFLAGS) -o "push_swap_debug"

debug_linux:
		@gdd $(HEAD) $(SRC) $(CFLAGS) -o "push_swap_debug"

clean:
		@$(RM) $(OBJ_DIR)

fclean: clean
		@$(RM) $(NAME)
		@$(RM) push_swap_debug
		@$(RM) push_swap_debug.dSYM

re: fclean all

.PONY: all clean fclean re