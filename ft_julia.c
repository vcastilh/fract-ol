/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 07:56:48 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/21 08:57:24 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_fractal *fractal)
{
	int	iter;

	fractal->i = 0;
	while (fractal->i < HEIGHT)
	{
		fractal->j = 0;
		while (fractal->j < WIDTH)
		{
			ft_win_to_view_j(fractal, fractal->i, fractal->j);
			fractal->z.mdl = pow(fractal->c.re, 2) + pow(fractal->c.im, 2);
			iter = 0;
			while (fractal->z.mdl <= DIVERGENCE && iter < MAX_ITER)
			{
				fractal->z = ft_complex(pow(fractal->z.re, 2)
						- pow(fractal->z.im, 2)
						+ fractal->c.re, 2 * fractal->z.re * fractal->z.im
						+ fractal->c.im);
				fractal->z.mdl = pow(fractal->z.re, 2) + pow(fractal->z.im, 2);
				iter++;
			}
			ft_pixel_to_image(fractal, fractal->i, fractal->j, ft_color(iter));
			fractal->j++;
		}
		fractal->i++;
	}
}
