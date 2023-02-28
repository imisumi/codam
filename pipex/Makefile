# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/28 00:51:40 by ichiro            #+#    #+#              #
#    Updated: 2023/02/27 13:58:12 by imisumi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

HEADER = includes/pipex.h

CFLAGS = -g -I include

cc = gcc

LIBFT = lib/libft/libft.a

OBJS_DIR = objs
SRC_DIR = src

INC := -I $(INCLUDE_DIR)

SRCS = pipex.c utils.c
# main.c utils.c

OBJS = $(addprefix $(OBJS_DIR)/,$(SRCS:.c=.o))

all:  $(LIBFT) $(NAME)

$(OBJS_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(cc) $(CFLAGS) $(INC) -I -c -o $@ $<

$(LIBFT):
	@$(MAKE) -C lib/libft

$(NAME): $(LIBFT) $(OBJS)
	@$(cc) $(CFLAGS) $(INC) -I $^ -o $(NAME)

clean:
	@rm -rf $(OBJS_DIR)
	@make clean -C lib/libft

fclean:
	@rm -rf $(OBJS_DIR)
	@rm -rf $(NAME)
	@make fclean -C lib/libft

re: fclean all

.PHONY: all clean fclean re