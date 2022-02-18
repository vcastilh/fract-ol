/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:24:26 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/18 13:57:49 by vcastilh         ###   ########.fr       */
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
//	else if (argv[1][0] == 'J')
//		ft_julia(&fractal, &mlx);
	//printf("re: %Lf\t im: %Lf\t", fractal.c.re, fractal.c.im);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}

void	ft_usage(void)
{
	write(1, "Error\n", 6);
}

void	ft_set_fractal(char **argv, t_fractal *fractal)
{
	fractal->max = ft_complex(2, 2);
	fractal->min = ft_complex(-2, -2);
	if (argv[1][0] == 'M')
	{
		fractal->name = argv[1];
	}
	else if (argv[1][0] == 'J')
	{
		fractal->name = argv[1];
		fractal->c = ft_complex(ft_atold(argv[2]),ft_atold(argv[3]));
	}
}

t_complex	ft_complex(long double re, long double im)
{
	t_complex	numb;
	
	numb.re = re;
	numb.im = im;
	return (numb);
}

void	ft_init_mlx(t_mlx *mlx, t_fractal *fractal)
{
	mlx->mlx_ptr = mlx_init();
	if (mlx->mlx_ptr == NULL)
		exit(1);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, fractal->name);
	if (mlx->win_ptr == NULL)
	{
		free(mlx->win_ptr);
		exit(1);
	}
	mlx->img = mlx_new_image(mlx->mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	mlx->img_addr = (char *)mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->line_size,
			&mlx->endian);
}

void	ft_win_to_view(t_fractal *fractal, int i, int j)
{
	fractal->s_x = (fractal->max.re - fractal->min.re) / WIDTH;
	fractal->s_y = (fractal->max.im - fractal->min.im) / HEIGHT;
	fractal->c.re = fractal->min.re + (double)(j * fractal->s_x);
	fractal->c.im = fractal->min.im + (double)(i * fractal->s_y);
	fractal->z.re = 0;
	fractal->z.im = 0;
}

void	ft_mandelbrot(t_fractal *fractal, t_mlx *mlx)
{
	int	i;
	int	j;
	int	iter;

	i = 0;
	while (i < HEIGHT)
	{
		j = 0;
		while (j < WIDTH)
		{
			ft_win_to_view(fractal, i, j);
			fractal->z.mdl = pow(fractal->c.re, 2) + pow(fractal->c.im, 2);
			iter = 0;
			while (fractal->z.mdl <= DIVERGENCE && iter < MAX_ITER)
			{
				fractal->z = ft_complex(pow(fractal->z.re,2) - pow(fractal->z.im, 2)
						+ fractal->c.re, 2 * fractal->z.re * fractal->z.im
						+ fractal->c.im);
				fractal->z.mdl = pow(fractal->z.re, 2) + pow(fractal->z.im, 2);
				iter++;
			}
			ft_pixel_to_image(mlx, i, j, ft_color(iter));
			j++;
		}
		i++;
	}
}

int	ft_color(int t)
{
	int	r;
	int	g;
	int b;

	r = (int)(9 * (1 - t) * pow(t, 3) * 150);
	g = (int)(15 * pow((1 - t), 2) * pow(t, 2) * 255);
	b = (int)(8.5 * pow((1 - t), 3) * t * 80);
	return ((int)(t << 24 | r << 16 | g << 8 | b));
}

void	ft_pixel_to_image(t_mlx *mlx, int i, int j, int clr)
{
	int	*p;

	p = (int *)&mlx->img_addr[(i * mlx->line_size + (j * (mlx->bpp/8)))];
	*p = clr;
}
