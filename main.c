/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:24:26 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/20 14:17:58 by vcastilh         ###   ########.fr       */
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
	if (argv[1][0] == 'M')
		ft_mandelbrot(&fractal);
	else if (argv[1][0] == 'J')
		ft_julia(&fractal);
	//printf("re: %Lf\t im: %Lf\t", fractal.c.re, fractal.c.im);
	mlx_put_image_to_window(fractal.mlx.mlx_ptr, fractal.mlx.win_ptr,
			fractal.mlx.img, 0, 0);
	//mlx_expose_hook(fractal.mlx.win_ptr, ft_expose_hook, &fractal);
	mlx_mouse_hook(fractal.mlx.win_ptr, ft_mouse_hook, &fractal);
	mlx_key_hook(fractal.mlx.win_ptr, ft_key_hook, &fractal);
	//mlx_hook(fractal.mlx.win_ptr, KEYPRESS, 1L << 0, ft_key_hook, &fractal);
	mlx_loop(fractal.mlx.mlx_ptr);
	return (0);
}

void	ft_usage(void)
{
	write(1, "Error\n", 6);
}
