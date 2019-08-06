# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/03 21:10:35 by mbeahan           #+#    #+#              #
#    Updated: 2019/08/06 20:11:55 by mbeahan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PUSH_SWAP = push_swap

CHECKER = checker

LIB = -I libft/libft.h -L./libft -lft
PRINTF = -I ft_printf/include/ft_printf.h -L./ft_printf -l ftprintf

SRC =   src/args_ops.c \
		src/first_ops.c \
		src/help_stack.c \
		src/help_stack2.c \
		src/help_stack3.c \
		src/second_ops.c \
		src/sort.c \
		src/visualize.c

OBJ = $(SRC:.c=.o)

HEADER = -I push_swap.h

all: $(PUSH_SWAP) $(CHECKER)

$(PUSH_SWAP):  $(OBJ)
	make -C libft/
	make -C ft_printf/
	gcc -Wall -Wextra -Werror $(OBJ) src/push_swap.c -o $(PUSH_SWAP) $(LIB) $(PRINTF)

$(CHECKER):  $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) src/checker.c -o $(CHECKER) $(LIB) $(PRINTF)

clean:
	rm -rf libft/*.o
	rm -rf ft_printf/temporary/*.o
	rm -rf src/*.o

fclean: clean
	rm -rf $(PUSH_SWAP) $(CHECKER)
	rm -rf libft/libft.a
	rm -rf ft_printf/libftprintf.a

re: fclean all