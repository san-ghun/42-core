# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 12:23:52 by sanghupa          #+#    #+#              #
#    Updated: 2023/05/12 15:06:14 by sanghupa         ###   ########.fr        #
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

MLX42		= libmlx42.a 
MLX42_DIR	= ./MLX42 
MLX42_I_DIR	= $(MLX42_DIR)/include
MLX42_PATH	= $(MLX42_DIR)/build/$(MLX42)

SRC_DIR		= ./src

NAME 		= fractol
SRC_NAME 	= $(SRC_DIR)/$(NAME).c \
				$(SRC_DIR)/fractol_error.c \

OBJ_NAME 	= $(SRC_NAME:.c=.o)

NAME_B 		= fractol_bonus
SRC_NAME_B 	= $(SRC_DIR)/$(NAME_B).c \
				$(SRC_DIR)/fractol_error.c \

OBJ_NAME_B 	= $(SRC_NAME_B:.c=.o)


# Main Command

# Don't forget to run "git submodule init && git submodule update"
all: $(NAME)

bonus: $(NAME_B)

clean:
		make clean -C $(LIBFT_DIR)
		$(RM) $(OBJ_NAME)
		$(RM) $(OBJ_NAME_B)

fclean: clean
		make fclean -C $(LIBFT_DIR)
		$(RM) $(LIBFT)
		$(RM) $(MLX42)
		$(RM) $(OBJ_NAME)
		$(RM) $(OBJ_NAME_B)
		$(RM) $(NAME)

re: fclean all


# Sub Command

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $< -I $(INC_DIR) -I $(LIBFT_I_DIR) -I $(MLX42_I_DIR)

$(LIBFT):
		make -C $(LIBFT_DIR)
		mv $(LIBFT_PATH) ./

$(MLX42):
		cmake -S $(MLX42_DIR) -B $(MLX42_DIR)/build
		cmake --build $(MLX42_DIR)/build -j4
		mv $(MLX42_PATH) ./

$(NAME): $(OBJ_NAME) $(LIBFT) $(MLX42)
		$(CC) $(CFLAGS) -o $@ $^ -I $(INC_DIR) -I $(LIBFT_I_DIR) -I $(MLX42_I_DIR) -ldl -lglfw -pthread -lm

$(NAME_B): $(OBJ_NAME_B) $(LIBFT) 
		$(CC) $(CFLAGS) -o $@ $^ -I $(INC_DIR) -I $(LIBFT_I_DIR) -I $(MLX42_I_DIR) -ldl -lglfw -pthread -lm


# Phony target

.PHONY: all clean fclean re bonus 