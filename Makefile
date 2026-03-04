# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: divalent <divalent@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/20 14:32:57 by divalent          #+#    #+#              #
#    Updated: 2024/11/19 17:07:03 by divalent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = $(addprefix ./src/, $(SOURCES))
SOURCES = philosophers.c actions.c parsing.c utils.c utils2.c ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_puthexnbr.c ft_strlen.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo "philosophers built"

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
