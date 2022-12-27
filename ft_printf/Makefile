# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 17:17:29 by sanghupa          #+#    #+#              #
#    Updated: 2022/12/27 01:13:52 by sanghupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libftprintf.a

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

AR			= ar -rcv
# -r : replace or add the specified files to the archive.
# -c : create archive without message. `ar: creating archive libft.a`
# -v : provide verbose output. `a` if the file is added and \
		`r` if the file replace a file already in the archive.

INC_DIR	= ./include

LIBFT		= libft.a
LIBFT_DIR	= ./libft
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

SRC_DIR	= ./src
SRC			= $(SRC_DIR)/ft_printf.c 

OBJ 		= $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAME)

clean:
		make clean -C $(LIBFT_DIR)
		$(RM) $(OBJ)

fclean: clean
		make fclean -C $(LIBFT_DIR)
		$(RM) $(NAME)

re: fclean all

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@ -I $(INC_DIR) -I $(LIBFT_DIR)

$(NAME): $(OBJ)
		cp $(LIBFT_PATH) $(NAME)
		$(AR) $@ $^

$(LIBFT):
		make -C $(LIBFT_DIR)

# Test Code

TEST = test.c

test: $(LIBFT) $(NAME) $(TEST)
		$(CC) $(TEST) -o $(TEST:.c=.out) $(NAME) -I $(INC_DIR) -I $(LIBFT_DIR) -g
		./$(TEST:.c=.out)
		rm $(TEST:.c=.out)
		rm -rf $(TEST:.c=.out.dSYM)

.PHONY: all clean fclean re bonus \
		test