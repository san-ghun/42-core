# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/11 12:23:52 by sanghupa          #+#    #+#              #
#    Updated: 2023/05/11 12:25:20 by sanghupa         ###   ########.fr        #
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

all: $(NAME)

bonus: $(NAME_B)

clean:
		make clean -C $(LIBFT_DIR)
		$(RM) $(OBJ_NAME)
		$(RM) $(OBJ_NAME_B)

fclean: clean
		make fclean -C $(LIBFT_DIR)
		$(RM) $(LIBFT)
		$(RM) $(OBJ_NAME)
		$(RM) $(OBJ_NAME_B)
		$(RM) $(NAME)

re: fclean all


# Sub Command

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $< -I $(INC_DIR) -I $(LIBFT_I_DIR)

$(LIBFT):
		make -C $(LIBFT_DIR)
		mv $(LIBFT_PATH) ./

$(NAME): $(OBJ_NAME) $(LIBFT) 
		$(CC) $(CFLAGS) -o $@ $^ -I $(INC_DIR) -I $(LIBFT_I_DIR)

$(NAME_B): $(OBJ_NAME_B) $(LIBFT) 
		$(CC) $(CFLAGS) -o $@ $^ -I $(INC_DIR) -I $(LIBFT_I_DIR)


# Phony target

.PHONY: all clean fclean re bonus 