/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:49:54 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/20 14:03:59 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_init_mlx(t_fractal *fractal)
{
	fractal->mlx.mlx_ptr = mlx_init();
	if (fractal->mlx.mlx_ptr == NULL)
		exit(1);
	fractal->mlx.win_ptr = mlx_new_window(fractal->mlx.mlx_ptr, WIDTH, HEIGHT, fractal->name);
	if (fractal->mlx.win_ptr == NULL)
	{
		free(fractal->mlx.win_ptr);
		exit(1);
	}
	fractal->mlx.img = mlx_new_image(fractal->mlx.mlx_ptr, IMG_WIDTH, IMG_HEIGHT);
	fractal->mlx.img_addr = (char *)mlx_get_data_addr(fractal->mlx.img, &fractal->mlx.bpp, &fractal->mlx.line_size,
			&fractal->mlx.endian);
}
