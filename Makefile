# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 10:11:30 by gpollast          #+#    #+#              #
#    Updated: 2025/07/01 12:04:45 by gpollast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = 	main.c \
		stack.c \
		utils.c \
		free_memory.c \
		instruction1.c \
		instruction2.c \
		instruction3.c \
		instruction4.c \
		algo.c

OBJ = $(SRC:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./includes -I./libft -g
LDFLAGS = -L./libft -lft

all: libft/libft.a $(NAME)

libft/libft.a:
	@$(MAKE) -C libft

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C libft clean
	@echo "Suppression des fichiers objets (project + libft)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@echo "Suppression de l'exécutable et de la librairie"

re: fclean all