/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 12:38:17 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/21 08:56:53 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_key_hook(int key, t_fractal *fractal)
{
	if (key == ESC)
	{
		mlx_destroy_image(fractal->mlx.mlx_ptr, fractal->mlx.img);
		mlx_destroy_window(fractal->mlx.mlx_ptr, fractal->mlx.win_ptr);
		mlx_destroy_display(fractal->mlx.mlx_ptr);
		free(fractal->mlx.mlx_ptr);
		exit(0);
	}
	return (0);
}

int	ft_expose_hook(t_fractal *fractal)
{
	mlx_put_image_to_window(fractal->mlx.mlx_ptr, fractal->mlx.win_ptr,
		fractal->mlx.img, 0, 0);
	return (0);
}

void	ft_zoom(int key, int x, int y, t_fractal *fractal)
{
	t_scale	scale;

	scale.x_ratio = (double)x / WIDTH;
	scale.y_ratio = (double)y / HEIGHT;
	if (key == ZOOM_IN)
	{
		fractal->delta.re = (1.05 * fractal->delta.re) - fractal->delta.re;
		fractal->delta.im = (1.05 * fractal->delta.im) - fractal->delta.im;
	}
	else
	{
		fractal->delta.re = ((1.0 / 1.05) * fractal->delta.re)
			- fractal->delta.re;
		fractal->delta.im = ((1.0 / 1.05) * fractal->delta.im)
			- fractal->delta.im;
	}
	fractal->min.re = fractal->min.re
		- (fractal->delta.re * scale.x_ratio);
	fractal->max.re = fractal->max.re
		+ (fractal->delta.re * (1 - scale.x_ratio));
	fractal->min.im = fractal->min.im
		- (fractal->delta.im * scale.y_ratio);
	fractal->max.im = fractal->max.im
		+ (fractal->delta.im * (1 - scale.y_ratio));
}

int	ft_mouse_hook(int key, int x, int y, t_fractal *fractal)
{
	if (key == ZOOM_IN)
	{
		ft_zoom(key, x, y, fractal);
		ft_check_fractal(fractal);
	}
	if (key == ZOOM_OUT)
	{
		ft_zoom(key, x, y, fractal);
		ft_check_fractal(fractal);
	}
	return (0);
}

int	ft_cross_hook(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx.mlx_ptr, fractal->mlx.img);
	mlx_destroy_window(fractal->mlx.mlx_ptr, fractal->mlx.win_ptr);
	mlx_destroy_display(fractal->mlx.mlx_ptr);
	free(fractal->mlx.mlx_ptr);
	exit(0);
	return (0);
}
