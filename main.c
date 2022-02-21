/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:24:26 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/21 04:14:51 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc < 2)
	{
		ft_usage();
		exit(1);
	}
	else if (ft_strncmp(argv[1], "Mandelbrot", 11) != 0
		&& (ft_strncmp(argv[1], "Julia", 6) == 0 && argc < 4))
	{
		ft_usage();
		exit(1);
	}
	ft_set_fractal(argv, &fractal);
	ft_init_mlx(&fractal);
	ft_check_fractal(&fractal);
	mlx_expose_hook(fractal.mlx.win_ptr, ft_expose_hook, &fractal);
	mlx_mouse_hook(fractal.mlx.win_ptr, ft_mouse_hook, &fractal);
	mlx_key_hook(fractal.mlx.win_ptr, ft_key_hook, &fractal);
	mlx_loop(fractal.mlx.mlx_ptr);
	return (0);
}

void	ft_check_fractal(t_fractal *fractal)
{
	if (*fractal->name == 'M')
		ft_mandelbrot(fractal);
	else
		ft_julia(fractal);
	mlx_put_image_to_window(fractal->mlx.mlx_ptr, fractal->mlx.win_ptr,
		fractal->mlx.img, 0, 0);
}

void	ft_usage(void)
{
	write(1, "Error\n", 6);
}
