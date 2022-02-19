/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pixel_to_image.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:36:52 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/18 18:37:16 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_pixel_to_image(t_mlx *mlx, int i, int j, int clr)
{
	int	*p;

	p = (int *)&mlx->img_addr[(i * mlx->line_size + (j * (mlx->bpp/8)))];
	*p = clr;
}
