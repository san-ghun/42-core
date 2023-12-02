# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 22:48:59 by sanghupa          #+#    #+#              #
#    Updated: 2023/12/02 14:13:17 by sanghupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc

CFLAGS		= -Wall -Werror -Wextra

RM			= rm

AR			= ar -rcv
# -r : replace or add the specified files to the archive.
# -c : create archive without message. `ar: creating archive libft.a`
# -v : provide verbose output. `a` if the file is added and \
		`r` if the file replace a file already in the archive.

NAME		= libft.a

INCLUDE		= ./include

SRC			= $(shell find ./src -iname "*.c")

OBJ 		= $(SRC:.c=.o)


all: $(NAME)

%.o: %.c
		@$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDE)

$(NAME): $(OBJ)
		@$(AR) $@ $^

clean:
		@$(RM) -f $(OBJ)

fclean: clean
		@$(RM) -f $(NAME)

re: fclean all

# Library Test Code

TEST = test.c

test: $(NAME) $(TEST)
		$(CC) $(TEST) -o $(TEST:.c=.out) $(NAME) -I $(INCLUDE) -g
		./$(TEST:.c=.out)
		rm -f $(TEST:.c=.out)
		rm -rf $(TEST:.c=.out.dSYM)

.PHONY: all clean fclean re test