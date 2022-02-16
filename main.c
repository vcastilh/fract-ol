/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:24:26 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/16 10:53:25 by vcastilh         ###   ########.fr       */
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
	printf("re: %Lf\t im: %Lf\t", fractal.c.re, fractal.c.im);
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
		fractal->c = ft_complex(0, 0);
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

