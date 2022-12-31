# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/26 17:17:29 by sanghupa          #+#    #+#              #
#    Updated: 2022/12/31 22:19:43 by sanghupa         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= cc
CFLAGS		= -Wall -Werror -Wextra

RM			= rm -f

INC_DIR	= ./include

LIBFT		= libft.a
LIBFT_DIR	= ./libft
LIBFT_PATH	= $(LIBFT_DIR)/$(LIBFT)

SRC_DIR	= ./src

SERVER = server
SRC_SERVER = $(SRC_DIR)/$(SERVER).c
OBJ_SERVER = $(SRC_SERVER:.c=.o)
SERVER_B = server_bonus
SRC_SERVER_B = $(SRC_DIR)/$(SERVER_B)_bonus.c
OBJ_SERVER_B = $(SRC_SERVER_B:.c=.o)

CLIENT = client_bonus
SRC_CLIENT = $(SRC_DIR)/$(CLIENT).c
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
CLIENT_B = client
SRC_CLIENT_B = $(SRC_DIR)/$(CLIENT_B)_bonus.c
OBJ_CLIENT_B = $(SRC_CLIENT_B:.c=.o)

all: $(SERVER) $(CLIENT)

bonus: $(LIBFT) $(SERVER_B) $(CLIENT_B)

clean:
		make clean -C $(LIBFT_DIR)
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
		$(RM) $(OBJ_SERVER_B) $(OBJ_CLIENT_B)

fclean: clean
		make fclean -C $(LIBFT_DIR)
		$(RM) $(OBJ_SERVER) $(OBJ_CLIENT)
		$(RM) $(OBJ_SERVER_B) $(OBJ_CLIENT_B)
		$(RM) $(SERVER) $(CLIENT)

re: fclean all

%.o: %.c
		$(CC) $(CFLAGS) -c -o $@ $^ -I $(INC_DIR) -I $(LIBFT_DIR)

$(LIBFT):
		make -C $(LIBFT_DIR)

$(SERVER): $(OBJ_SERVER) $(LIBFT)
		$(CC) $(CFLAGS) -o $@ $< -I $(INC_DIR) -I $(LIBFT_DIR)

$(CLIENT): $(OBJ_CLIENT) $(LIBFT)
		$(CC) $(CFLAGS) -o $@ $< -I $(INC_DIR) -I $(LIBFT_DIR)

$(SERVER_B): $(OBJ_SERVER_B) $(LIBFT)
		$(CC) $(CFLAGS) -o $@ $< -I $(INC_DIR) -I $(LIBFT_DIR)

$(CLIENT_B): $(OBJ_CLIENT_B) $(LIBFT)
		$(CC) $(CFLAGS) -o $@ $< -I $(INC_DIR) -I $(LIBFT_DIR)

.PHONY: all clean fclean re bonus 
