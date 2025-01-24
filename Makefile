# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agamay <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 17:31:12 by agamay            #+#    #+#              #
#    Updated: 2024/12/02 17:32:21 by agamay           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = push_swap.c \
	push_algo_1.c \
	push_algo_2.c \
	push_parser.c \
	push_lst01.c \
	push_lst02.c \
	push_fct01.c \
	push_utils.c

LIB = libft.a

OBJ = $(SRC:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

CC = cc

$(NAME): libft $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

test: libft $(OBJ_TEST)
	$(CC) -o $@ $(OBJ_TEST) $(LIB)

libft:
	make -sC ../libft
	cp ../libft/libft.a ./
	make fclean -sC ../libft

all: $(OBJ) $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)

fclean: clean
	rm -f $(NAME)
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re test libft
