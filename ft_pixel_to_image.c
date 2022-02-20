/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_to_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:36:52 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/20 13:51:57 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_to_image(t_fractal *fractal, int i, int j, int clr)
{
	int	*p;

	p = (int *)&fractal->mlx.img_addr[(i * fractal->mlx.line_size + (j * (fractal->mlx.bpp/8)))];
	*p = clr;
}
