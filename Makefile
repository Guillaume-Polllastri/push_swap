# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpollast <gpollast@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/30 10:11:30 by gpollast          #+#    #+#              #
#    Updated: 2025/07/11 14:31:39 by gpollast         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
NAME_BONUS = checker

SRC = 	src/main.c \
		src/parse.c \
		src/parse_utils.c \
		src/stack.c \
		src/utils.c \
		src/free_memory.c \
		src/instruction1.c \
		src/instruction2.c \
		src/instruction3.c \
		src/instruction4.c \
		src/algo.c \
		src/algo_condition.c \
		src/algo_utils.c

OBJ = $(SRC:.c=.o)

SRC_BONUS = src_bonus/checker.c \
			src_bonus/check_instructions.c \
			src_bonus/get_next_line.c \
			src_bonus/get_next_line_utils.c \
			src/parse.c \
			src/parse_utils.c \
			src/stack.c \
			src/utils.c \
			src/free_memory.c \
			src/instruction1.c \
			src/instruction2.c \
			src/instruction3.c \
			src/instruction4.c \
			src/algo_condition.c

OBJ_BONUS = $(SRC_BONUS:.c=.o)

CC = gcc
CFLAGS = -Wall -Werror -Wextra -I./includes -I./libft -g
LDFLAGS = -L./libft -lft

all: libft/libft.a $(NAME)

libft/libft.a:
	@echo "Compiling libft..."
	@$(MAKE) -C libft --silent
	@echo "✅ Libft compiled successfully"

val:
	valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./$(NAME) $(ARGS)

$(NAME): $(OBJ)
	@echo "Compiling $(NAME)..."
	@$(CC) $(OBJ) $(CFLAGS) $(LDFLAGS) -o $(NAME)
	@echo "✅ $(NAME) compiled successfully"

bonus: libft/libft.a $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@echo "Compiling $(NAME_BONUS)..."
	@$(CC) $(OBJ_BONUS) $(CFLAGS) $(LDFLAGS) -o $(NAME_BONUS)
	@echo "✅ $(NAME_BONUS) compiled successfully"

clean:
	@rm -f $(OBJ) $(OBJ_BONUS)
	@$(MAKE) -C libft clean --silent
	@echo "✅ Object files removed (project + libft)"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@$(MAKE) -C libft fclean --silent
	@echo "✅ Executable and library removed"

re: fclean all

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@