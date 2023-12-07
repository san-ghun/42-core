# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 12:21:54 by sanghupa          #+#    #+#              #
#    Updated: 2023/12/07 21:55:42 by sanghupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =============================================================================
# Alias
# =============================================================================

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

UNAME   	:= $(shell uname)

SRC_DIR		= ./src

NAME 		= miniRT
SRC_NAME 	= $(shell find ./src -iname "*.c")

OBJ_NAME 	= $(SRC_NAME:.c=.o)

# NAME_B 		= miniRT_bonus
# SRC_NAME_B 	= $(SRC_DIR)/$(NAME_B).c \
# 				$(SRC_DIR)/$(NAME_B)_util.c \

# OBJ_NAME_B 	= $(SRC_NAME_B:.c=.o)

HEADERS		= -I $(INC_DIR) -I $(LIBFT_I_DIR) -I $(MLX_I_DIR)

INC_DIR		= ./include
LIB_DIR		= ./lib

LIBFT		= libft.a
LIBFT_DIR	= ./libft
LIBFT_I_DIR	= $(LIBFT_DIR)/include


# =============================================================================
# OS specific configs
# =============================================================================

MLX			= libmlx.a
MLX_AR_DIR	= ./mlx
MLX_DIR		= ./minilibx-linux
MLX_I_DIR	= $(MLX_DIR)
MLX_PATH	= $(MLX_DIR)/$(MLX)
MLX_FLAGS	= -lmlx

ifeq ($(UNAME), Darwin) # iMac / iOS
	CC			= gcc
	MLX			= libmlx.dylib
	MLX_DIR		= ./mlx
	MLX_FLAGS	+= -framework OpenGL -framework AppKit
else ifeq ($(UNAME), FreeBSD) # FreeBSD
	CC			= clang
else #Linux and others...
	CC			= cc
	HEADERS		+= -I /usr/include
	MLX			= libmlx.a
	MLX_DIR		= ./minilibx-linux
	MLX_FLAGS	+= -lXext -lX11 -lm -lz -lbsd
endif


# =============================================================================
# Main Command
# =============================================================================

all: $(NAME)

# bonus: $(NAME_B)

clean:
		@make clean -sC $(LIBFT_DIR)
		@make clean -sC $(MLX_DIR)
		@$(RM) $(OBJ_NAME)
		@$(RM) $(OBJ_NAME_B)

fclean:
		@make fclean -sC $(LIBFT_DIR)
		@make clean -sC $(MLX_DIR)
		@$(RM) $(LIBFT)
		@$(RM) $(MLX)
		@$(RM) $(OBJ_NAME)
		@$(RM) $(OBJ_NAME_B)
		@$(RM) $(NAME)

re: fclean all

# re_bonus: fclean bonus


# =============================================================================
# Sub Command
# =============================================================================

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $< $(HEADERS) -I $(MLX_AR_DIR)  

$(LIBFT):
		@make -sC $(LIBFT_DIR)
		@mv $(LIBFT_DIR)/$(LIBFT) ./

$(MLX):
		@tar -xf $(MLX_AR_DIR)/minilibx-linux.tgz
		@make -sC $(MLX_DIR)
		@mv $(MLX_DIR)/libmlx.a ./$(MLX)

dev: $(LIBFT) $(MLX)
ifeq ($(UNAME), Darwin) # iMac / iOS
		$(CC) -g -o $(NAME) $(SRC_NAME) $^ $(HEADERS) -I $(MLX_AR_DIR) -L $(MLX_AR_DIR) $(MLX_FLAGS)
		install_name_tool -change $(MLX) $(MLX_AR_DIR)/$(MLX) $(NAME)
else #Linux and others...
#		$(CC) -fsanitize=thread -g -o $(NAME) $(SRC_NAME) $^ $(HEADERS) $(MLX_FLAGS)
#		$(CC) -fsanitize=address -g -o $(NAME) $(SRC_NAME) $^ $(HEADERS) $(MLX_FLAGS)
		$(CC) -g -o $(NAME) $(SRC_NAME) $^ $(HEADERS) -I $(MLX_AR_DIR) $(MLX_FLAGS)
endif

$(NAME): $(OBJ_NAME) $(LIBFT) $(MLX)
ifeq ($(UNAME), Darwin) # iMac / iOS
		$(CC) $(CFLAGS) -o $@ $^ $(HEADERS) -I $(MLX_AR_DIR) -L $(MLX_AR_DIR) $(MLX_FLAGS)
		install_name_tool -change $(MLX) $(MLX_AR_DIR)/$(MLX) $(NAME)
else #Linux and others...
#		$(CC) $(CFLAGS) -fsanitize=address -g -o $@ $^ $(HEADERS) $(MLX_FLAGS)
		$(CC) $(CFLAGS) -o $@ $^ $(HEADERS) -I $(MLX_AR_DIR) $(MLX_FLAGS)
endif

# $(NAME_B): $(OBJ_NAME_B) $(LIBFT) 
# 		@$(CC) $(CFLAGS) -o $@ $^ $(HEADERS) -I $(MLX_AR_DIR) $(MLX_FLAGS)

show:
		@printf "UNAME		: $(UNAME)\n"
		@printf "NAME  		: $(NAME)\n"
		@printf "CC		: $(CC)\n"
		@printf "CFLAGS		: $(CFLAGS)\n"
		@printf "MLX_FLAGS	: $(MLX_FLAGS)\n"
		@printf "SRC		: $(SRC_NAME)\n"
		@printf "OBJ		: $(OBJ_NAME)\n"

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


# =============================================================================
# Test Code 
# =============================================================================

TEST 		= test.c
TMP 		= $(SRC_DIR)/$(NAME).c \
				$(SRC_DIR)/$(NAME)_util.c \

test: $(LIBFT)
		$(CC) $(TEST) -o $(TEST:.c=.out) $(TMP) $^ $(HEADERS) $(MLX_FLAGS)

tclean: 
		make fclean -C $(LIBFT_DIR)
		$(RM) $(LIBFT)
		$(RM) -f test.o test.out

# Phony target

.PHONY: all clean fclean re bonus re_bonus party
