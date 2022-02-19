# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/07 17:41:34 by vcastilh          #+#    #+#              #
#    Updated: 2022/02/19 08:29:07 by vcastilh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractal
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


CC =clang
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address  -I. -I./libft -I./minilibx-linux -c
OBJS = $(SRC:%.c=%.o)
#LIBFTDIR = libft

all: $(NAME)
$(NAME): LIBFTDIR MLX $(OBJS) 
	$(CC) $(OBJS) -o $(NAME) -fsanitize=address  -Llibft -lft -I./libft -Lminilibx-linux -lmlx -L/usr/lib -Iminilibx-linux -lXext -lX11 -lm -lz
$(OBJS): $(SRC)
	$(CC) $(CFLAGS) $(SRC)
LIBFTDIR:
	make -C libft 
#	make -C clean libft
MLX:
	make -C minilibx-linux
clean:
	rm -rf $(OBJS)
fclean: clean
	rm -rf $(NAME)
re: fclean all
