/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_mlx.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:49:54 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/18 18:50:14 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
