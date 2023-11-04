# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/14 12:21:54 by sanghupa          #+#    #+#              #
#    Updated: 2023/11/04 18:08:22 by sanghupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Alias

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

INC_DIR		= ./include

SRC_DIR		= ./src

NAME 		= philo_bonus
SRC_NAME 	= $(shell find ./src -iname "*.c")

OBJ_NAME 	= $(SRC_NAME:.c=.o)


# Main Command

all: $(NAME)

clean:
		@$(RM) $(OBJ_NAME)

fclean: clean
		@$(RM) $(OBJ_NAME)
		@$(RM) $(NAME)

re: fclean all


# Sub Command

dev:
#		$(CC) -fsanitize=address -g -o $(NAME) $(SRC_NAME) $^ -I $(INC_DIR)
		$(CC) -fsanitize=thread -g -o $(NAME) $(SRC_NAME) $^ -I $(INC_DIR) 
#		$(CC) -g -o $(NAME) $(SRC_NAME) $^ -I $(INC_DIR) 

%.o: %.c
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(INC_DIR)

$(NAME): $(OBJ_NAME)
#		@$(CC) $(CFLAGS) -o $@ $^ -I $(INC_DIR)
		@$(CC) $(CFLAGS) -g -o $@ $^ -I $(INC_DIR)


# Test Code 

TEST 		= test.c
TMP 		= $(SRC_DIR)/$(NAME)_util.c \
#				$(SRC_DIR)/$(NAME).c \

test: 
		$(CC) $(TEST) -o $(TEST:.c=.out) $(TMP) $^ -I $(INC_DIR)

tclean: 
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

.PHONY: all clean fclean re party 
