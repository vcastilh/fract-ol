/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 07:56:48 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/19 09:46:34 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_julia(t_fractal *fractal, t_mlx *mlx)
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
			ft_win_to_view_j(fractal, i, j);
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
