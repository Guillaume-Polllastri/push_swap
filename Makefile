# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 10:11:30 by gpollast          #+#    #+#              #
#    Updated: 2025/07/07 13:05:55 by gpollast         ###   ########.fr        #
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
CFLAGS = -Wall -Werror -Wextra -I./includes -I./libft -I./ft_printf -g
LDFLAGS = -L./libft -lft -L./ft_printf -lftprintf

all: libft/libft.a ft_printf/libftprintf.a $(NAME)

libft/libft.a:
	@$(MAKE) -C libft

ft_printf/libftprintf.a:
	@$(MAKE) -C ft_printf

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)

clean:
	@rm -f $(OBJ)
	@$(MAKE) -C libft clean
	@$(MAKE) -C ft_printf clean
	@echo "Suppression des fichiers objets (project + libft)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C libft fclean
	@$(MAKE) -C ft_printf fclean
	@echo "Suppression de l'exécutable et de la librairie"

re: fclean all