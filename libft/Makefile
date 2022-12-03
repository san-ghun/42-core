# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 22:48:59 by sanghupa          #+#    #+#              #
#    Updated: 2022/12/03 01:04:01 by sanghupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

AR			= ar -rcv

NAME		= libft.a

INCLUDE		= .

SRC			= ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c \
				ft_isprint.c ft_strlen.c \

SRC_B		= ft_strjoin.c \

OBJ 		= $(SRC:.c=.o)

OBJ_B 		= $(SRC_B:.c=.o)

all: $(NAME)

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $< -I $(INCLUDE)

$(NAME): $(OBJ)
		$(AR) $@ $^

clean:
		$(RM) $(OBJ) $(OBJ_B)

fclean: clean
		$(RM) $(NAME)

re: fclean all

bonus: $(OBJ_B)
		$(AR) $(NAME) $^

.PHONY: all clean fclean re bonus
