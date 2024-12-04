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
	push_parser.c \
	push_lstfct01.c \
	push_lstfct02.c \
	push_fct01.c \
	push_fct02.c \

SRC_TEST = test01.c

LIB = libft.a

OBJ = $(SRC:.c=.o)

OBJ_TEST = $(SRC_TEST:.c=.o)

CFLAGS = -Wall -Werror -Wextra -g

CC = cc

$(NAME): libft $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIB)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $^

test: libft $(OBJ_TEST)
	$(CC) -o $@ $(OBJ_TEST) $(LIB)

libft:
	make -C ../libft
	cp ../libft/libft.a ./
	make fclean -C ../libft

all: $(OBJ) $(NAME)

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_TEST)

fclean: clean
	rm -f $(NAME)
	rm -f libft.a

re: fclean all

.PHONY: all clean fclean re test libft
