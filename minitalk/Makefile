# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 17:17:29 by sanghupa          #+#    #+#              #
#    Updated: 2023/01/06 01:26:41 by sanghupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

INC_DIR	= ./include

# LIBFT		= libft.a
# LIBFT_DIR	= ./libft
# LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)
LIBFT_DIR	= ./

SRC_DIR	= ./src

NAME = server
SRC_NAME = $(SRC_DIR)/$(NAME).c $(SRC_DIR)/minitalk_error.c
OBJ_NAME = $(SRC_NAME:.c=.o)
NAME_SB = server_bonus
SRC_NAME_SB = $(SRC_DIR)/$(NAME_SB).c
OBJ_NAME_SB = $(SRC_NAME_SB:.c=.o)

NAME_C = client
SRC_NAME_C = $(SRC_DIR)/$(NAME_C).c $(SRC_DIR)/minitalk_error.c
OBJ_NAME_C = $(SRC_NAME_C:.c=.o)
NAME_CB = client_bonus
SRC_NAME_CB = $(SRC_DIR)/$(NAME_CB).c
OBJ_NAME_CB = $(SRC_NAME_CB:.c=.o)

all: $(NAME) $(NAME_C)

bonus: $(NAME_SB) $(NAME_CB)

clean:
#		make clean -C $(LIBFT_DIR)
		$(RM) $(OBJ_NAME) $(OBJ_NAME_C)
		$(RM) $(OBJ_NAME_SB) $(OBJ_NAME_CB)

fclean: clean
#		make fclean -C $(LIBFT_DIR)
		$(RM) $(OBJ_NAME) $(OBJ_NAME_C)
		$(RM) $(OBJ_NAME_SB) $(OBJ_NAME_CB)
		$(RM) $(NAME) $(NAME_C)

re: fclean all

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $< -I $(INC_DIR) -I $(LIBFT_DIR)

# $(LIBFT):
# 		make -C $(LIBFT_DIR)

$(NAME): $(OBJ_NAME) $(LIBFT)
		$(CC) $(CFLAGS) -o $@ $^ -I $(INC_DIR) -I $(LIBFT_DIR)

$(NAME_C): $(OBJ_NAME_C) $(LIBFT)
		$(CC) $(CFLAGS) -o $@ $^ -I $(INC_DIR) -I $(LIBFT_DIR)

$(NAME_SB): $(OBJ_NAME_SB) $(LIBFT)
		$(CC) $(CFLAGS) -o $@ $^ -I $(INC_DIR) -I $(LIBFT_DIR)

$(NAME_CB): $(OBJ_NAME_CB) $(LIBFT)
		$(CC) $(CFLAGS) -o $@ $^ -I $(INC_DIR) -I $(LIBFT_DIR)

.PHONY: all clean fclean re bonus 
