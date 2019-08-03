# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/03 21:10:35 by mbeahan           #+#    #+#              #
#    Updated: 2019/08/03 23:24:14 by mbeahan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

NAME2 = checker

LIB = -I libft/libft.h -L./libft -lft
PRINTF = -I ft_printf/include/ft_printf.h -L./ft_printf -l ftprintf

SRC =   first_op.c \
		help_func2.c \
		help_functions.c \
		second_op.c \
		sort.c 
		
OBJ = $(SRC:.c=.o)

HEADER = -I push_swap.h

all: $(NAME1) $(NAME2)

$(NAME1):  $(OBJ)
	make -C libft/
	make -C ft_printf/
	gcc -Wall -Wextra -Werror $(OBJ) push_swap.c -o $(NAME1) $(LIB) $(PRINTF)

$(NAME2):  $(OBJ)
	gcc -Wall -Wextra -Werror $(OBJ) checker.c -o $(NAME2) $(LIB) $(PRINTF)

clean:
	rm -rf libft/*.o
	rm -rf ft_printf/temporary/*.o
	rm -rf *.o

fclean: clean
	rm -rf $(NAME1)
	rm -rf libft/libft.a
	rm -rf ft_printf/libftprintf.a

re: fclean all

debugp:
	 gcc -ggdb  first_op.c help_func2.c help_functions.c push_swap.c second_op.c sort.c $(LIB) $(PRINTF)

debugc:
	gcc -ggdb first_op.c help_func2.c help_functions.c checker.c second_op.c sort.c $(LIB) $(PRINTF)