# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 17:17:29 by sanghupa          #+#    #+#              #
#    Updated: 2022/12/26 20:28:53 by sanghupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

AR			= ar -rcv
# -r : replace or add the specified files to the archive.
# -c : create archive without message. `ar: creating archive libft.a`
# -v : provide verbose output. `a` if the file is added and \
		`r` if the file replace a file already in the archive.

NAME		= libftprintf.a

INCLUDE		= ./include

LIBFT_PATH	= ./libft

LIBFT	= $(LIBFT_PATH)/libft.a

SRC_PATH	= ./src

SRC			= $(SRC_PATH)/ft_printf.c 

OBJ 		= $(SRC:.c=.o)

all: $(LIBFT) $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDE)

$(LIBFT):
		make -C $(LIBFT_PATH)

$(NAME): $(OBJ)
		cp $(LIBFT) $(NAME)
		$(AR) $@ $^

clean:
		make clean -C $(LIBFT_PATH)
		$(RM) $(OBJ)

fclean: clean
		make fclean -C $(LIBFT_PATH)
		$(RM) $(NAME)

re: fclean all

bonus: $(NAME)

.PHONY: all clean fclean re bonus