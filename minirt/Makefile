# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 12:21:54 by sanghupa          #+#    #+#              #
#    Updated: 2023/12/02 15:57:11 by sanghupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Alias

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

INC_DIR		= ./include

LIBFT		= libft.a
LIBFT_DIR	= ./libft
LIBFT_I_DIR	= $(LIBFT_DIR)/include
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

LIB_DIR		= ./lib
MLX			= libmlx_Linux.a 
MLX_PATH	= $(LIB_DIR)/$(MLX)
MLX_LINKER	= -lXext -lX11 -lm -lz

HEADERS		= -I $(INC_DIR) -I $(LIBFT_I_DIR) $(MLX_LINKER)

SRC_DIR		= ./src

NAME 		= miniRT
SRC_NAME 	= $(shell find ./src -iname "*.c")

OBJ_NAME 	= $(SRC_NAME:.c=.o)

NAME_B 		= miniRT_bonus
SRC_NAME_B 	= $(SRC_DIR)/$(NAME_B).c \
				$(SRC_DIR)/$(NAME_B)_util.c \

OBJ_NAME_B 	= $(SRC_NAME_B:.c=.o)


# Main Command

all: $(NAME)

bonus: $(NAME_B)

clean:
		@make clean -C $(LIBFT_DIR)
		@$(RM) $(OBJ_NAME)
		@$(RM) $(OBJ_NAME_B)

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@$(RM) $(LIBFT)
		@$(RM) $(OBJ_NAME)
		@$(RM) $(OBJ_NAME_B)
		@$(RM) $(NAME)

re: fclean all

re_bonus: fclean bonus

# Sub Command

%.o: %.c
		@$(CC) $(CFLAGS) -c -o $@ $< $(HEADERS)

$(LIBFT):
		@make -C $(LIBFT_DIR)
		@mv $(LIBFT_PATH) ./

$(NAME): $(OBJ_NAME) $(LIBFT) 
		@$(CC) $(CFLAGS) -o $@ $^ $(MLX_PATH) $(HEADERS)
#		@$(CC) $(CFLAGS) -fsanitize=address -g -o $@ $^ -I $(INC_DIR) -I $(LIBFT_I_DIR)

$(NAME_B): $(OBJ_NAME_B) $(LIBFT) 
		@$(CC) $(CFLAGS) -o $@ $^ $(MLX_PATH) $(HEADERS)


# Test Code 

TEST 		= test.c
TMP 		= $(SRC_DIR)/$(NAME).c \
				$(SRC_DIR)/$(NAME)_util.c \

test: $(LIBFT)
		$(CC) $(TEST) -o $(TEST:.c=.out) $(TMP) $^ -I $(INC_DIR) -I $(LIBFT_I_DIR)

tclean: 
		make fclean -C $(LIBFT_DIR)
		$(RM) $(LIBFT)
		$(RM) -f test.o test.out

party:
					@printf "\033c"
					@echo "\n\033[35m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[1;33m♪┗(・o･)┓♪"
					@sleep 1
					@printf "\033c"
					@echo "\n\033[36m♪┏(・o･)┛♪"
					@sleep 1
					@printf "\033c"
					@echo "\033[34m♪┗(・o･)┓♪\n"

# Phony target

.PHONY: all clean fclean re bonus re_bonus party
