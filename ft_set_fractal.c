/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:57:23 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/20 14:04:05 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_fractal(char **argv, t_fractal *fractal)
{
	fractal->max = ft_complex(2, 2);
	fractal->min = ft_complex(-2, -2);
	if (argv[1][0] == 'M')
	{
		fractal->name = argv[1];
		fractal->delta.re = fractal->max.re - fractal->min.re;
		fractal->delta.im = fractal->max.im - fractal->min.im;
	}
	else if (argv[1][0] == 'J')
	{
		fractal->name = argv[1];
		fractal->c = ft_complex(ft_atold(argv[2]),ft_atold(argv[3]));
		fractal->delta.re = fractal->max.re - fractal->min.re;
		fractal->delta.im = fractal->max.im - fractal->min.im;
	}
}
