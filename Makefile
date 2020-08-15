# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lmedusa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/13 23:43:58 by lmedusa           #+#    #+#              #
#    Updated: 2020/08/13 23:44:00 by lmedusa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
HEADER = ft_printf.h

SRC = ft_printf.c parser_flags.c proc_char.c proc_hex_ptr.c proc_int.c processor.c\
util_atoi.c util_itoa.c util_print.c utils_other.c

OBJ = $(SRC:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re so

all: $(NAME)

$(NAME): $(OBJ)
		ar rcs $@ $^

%.o: %.c $(HEADER)
		$(CC) $(CFLAGS) -c $< -o $@

clean:
		@rm -f $(OBJ) $(BONUS_SRC:.c=.o)

fclean: clean
		@rm -f $(NAME)

re: fclean $(NAME)

so:
		gcc -c $(CFLAGS) -fPIC *.c
		gcc -shared -o libft.so *.o
