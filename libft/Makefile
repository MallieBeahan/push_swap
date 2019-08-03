# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbeahan <mbeahan@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/14 20:47:05 by mbeahan           #+#    #+#              #
#    Updated: 2019/08/03 22:24:00 by mbeahan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
FLAG = -Wall -Werror -Wextra
FILES = ft_bzero.c \
		ft_atoi.c \
		ft_isdigit.c \
		ft_memalloc.c \
		ft_strequ.c \
		ft_strsub.c \
		ft_strsplit.c \
		ft_putstr_fd.c \
		ft_strchr.c \
		ft_strdel.c \
		ft_strjoin.c \
		ft_strlen.c \
		ft_strnew.c \
		get_next_line.c

OBJ =	ft_bzero.o \
		ft_atoi.o \
		ft_isdigit.o \
		ft_memalloc.o \
		ft_strequ.o \
		ft_strsub.o \
		ft_strsplit.o \
		ft_putstr_fd.o \
		ft_strchr.o \
		ft_strdel.o \
		ft_strjoin.o \
		ft_strlen.o \
		ft_strnew.o \
		get_next_line.o

$(NAME) :
	gcc $(FLAG) -c $(FILES)
	ar rc $(NAME) $(OBJ)

all : $(NAME)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all
