# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 22:48:59 by sanghupa          #+#    #+#              #
#    Updated: 2022/12/05 19:23:42 by sanghupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc

CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

AR			= ar -rcv

NAME		= libft.a

INCLUDE		= .

SRC			= ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c \
				ft_isprint.c ft_strlen.c ft_strlcpy.c ft_strlcat.c \
				ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
				ft_strncmp.c ft_strnstr.c ft_atoi.c ft_strdup.c \
				ft_memset.c ft_bzero.c \

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
