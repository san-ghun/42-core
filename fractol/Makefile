# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 12:23:52 by sanghupa          #+#    #+#              #
#    Updated: 2023/06/02 16:35:01 by sanghupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Alias

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

RM			= rm

INC_DIR		= ./include

LIBFT		= libft.a
LIBFT_DIR	= ./libft
LIBFT_I_DIR	= $(LIBFT_DIR)/include
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

MLX42		= libmlx42.a 
MLX42_DIR	= ./MLX42
MLX42_I_DIR	= $(MLX42_DIR)/include
MLX42_PATH	= $(MLX42_DIR)/build/$(MLX42)

HEADERS		= -I $(INC_DIR) -I $(LIBFT_I_DIR) -I $(MLX42_I_DIR)
LINUX_LINK	= -ldl -lglfw -pthread -lm

SRC_DIR		= ./src

NAME 		= fractol
SRC_NAME 	= $(SRC_DIR)/$(NAME).c \
				$(SRC_DIR)/$(NAME)_init.c \
				$(SRC_DIR)/$(NAME)_draw.c \
				$(SRC_DIR)/$(NAME)_control.c \
				$(SRC_DIR)/$(NAME)_utils.c \
				$(SRC_DIR)/$(NAME)_error.c \

OBJ_NAME 	= $(SRC_NAME:.c=.o)

NAME_B 		= fractol_bonus
SRC_NAME_B 	= $(SRC_DIR)/$(NAME).c \
				$(SRC_DIR)/$(NAME)_init.c \
				$(SRC_DIR)/$(NAME)_draw.c \
				$(SRC_DIR)/$(NAME)_control.c \
				$(SRC_DIR)/$(NAME)_utils.c \
				$(SRC_DIR)/$(NAME)_error.c \

OBJ_NAME_B 	= $(SRC_NAME_B:.c=.o)


# Main Command

# Don't forget to run "git submodule init && git submodule update"
all: $(NAME)

bonus: $(NAME_B)

clean:
		@make clean -C $(LIBFT_DIR)
		@$(RM) -f $(OBJ_NAME)
		@$(RM) -f $(OBJ_NAME_B)
		@$(RM) -rf $(MLX42_DIR)/build

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@$(RM) -f $(LIBFT)
		@$(RM) -f $(MLX42)
		@$(RM) -f $(OBJ_NAME)
		@$(RM) -f $(OBJ_NAME_B)
		@$(RM) -f $(NAME)
		@$(RM) -f $(NAME_B)

re: fclean all


# Sub Command

%.o: %.c
		@$(CC) $(CFLAGS) -c -o $@ $< $(HEADERS)

$(LIBFT):
		@make -C $(LIBFT_DIR)
		@mv $(LIBFT_PATH) ./

$(MLX42):
		@cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
		@cmake --build $(MLX42_DIR)/build -j4
		@mv $(MLX42_PATH) ./

$(NAME): $(OBJ_NAME) $(LIBFT) $(MLX42)
		@$(CC) $(CFLAGS) -o $@ $^ $(HEADERS) $(LINUX_LINK)

$(NAME_B): $(OBJ_NAME_B) $(LIBFT) $(MLX42)
		@$(CC) $(CFLAGS) -o $@ $^ $(HEADERS) $(LINUX_LINK)

# Test Code 
# to test the installation of MLX42

TEST = test.c

test: $(MLX42)
		$(CC) $(TEST) -o $(TEST:.c=.out) $^ -I $(MLX42_I_DIR) $(LINUX_LINK)
		./$(TEST:.c=.out)

tclean: 
		$(RM) -f test.o test.out

# Phony target

.PHONY: all clean fclean re bonus 