# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 17:41:34 by vcastilh          #+#    #+#              #
#    Updated: 2022/02/21 09:58:48 by vcastilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
SRC = main.c \
	  ft_set_fractal.c \
	  ft_init_mlx.c \
	  ft_color.c \
	  ft_complex.c \
	  ft_mandelbrot.c \
	  ft_julia.c \
	  ft_win_to_view_m.c \
	  ft_win_to_view_j.c \
	  ft_pixel_to_image.c \
	  ft_hooks.c \


CC = gcc
CFLAGS = -Wall -Wextra -Werror -g3 -O3 -I. -I./libft -I./minilibx-linux -c
OBJS = $(SRC:%.c=%.o)
LIBFTDIR = libft
MLXDIR = minilibx-linux
all: $(NAME)
$(NAME):  $(OBJS) 
	make -C libft
	make -C minilibx-linux
	$(CC) $(OBJS) -Llibft -lft -I./libft -Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz -o $(NAME)
$(OBJS): $(SRC)
	$(CC) $(CFLAGS) $(SRC)
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
