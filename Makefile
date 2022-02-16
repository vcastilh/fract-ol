# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 17:41:34 by vcastilh          #+#    #+#              #
#    Updated: 2022/02/16 07:43:36 by vcastilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractal
SRC = main.c \

CC =gcc
CFLAGS = -Wall -Wextra -Werror -g3 -I. -I./libft -I./minilibx-linux -c
OBJS = $(SRC:%.c=%.o)
#LIBFTDIR = libft

all: $(NAME)
$(NAME): LIBFTDIR $(OBJS) 
	$(CC) $(OBJS) -o $(NAME) -Llibft -lft -I./libft -Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz
$(OBJS): $(SRC)
	$(CC) $(CFLAGS) $(SRC)
LIBFTDIR:
	make -C libft 
#	make -C clean libft 
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
