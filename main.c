/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:24:26 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/19 22:07:35 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_fractal	fractal;
	t_mlx		mlx;

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
	ft_init_mlx(&mlx, &fractal);
	if (argv[1][0] == 'M')
		ft_mandelbrot(&fractal, &mlx);
	else if (argv[1][0] == 'J')
		ft_julia(&fractal, &mlx);
	//printf("re: %Lf\t im: %Lf\t", fractal.c.re, fractal.c.im);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img, 0, 0);
	mlx_hook(mlx.win_ptr, KEYPRESS, 1L << 0, ft_key_hook, &mlx);
	mlx_expose_hook(mlx.win_ptr, ft_expose_hook, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

void	ft_usage(void)
{
	write(1, "Error\n", 6);
}
