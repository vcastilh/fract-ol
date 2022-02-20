/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_to_view_j.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 08:01:18 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/20 13:54:04 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_win_to_view_j(t_fractal *fractal, int i, int j)
{
	fractal->s_x = fractal->delta.re / WIDTH;
	fractal->s_y = fractal->delta.im / HEIGHT;
	fractal->z.re = fractal->min.re + (double)(j * fractal->s_x);
	fractal->z.im = fractal->min.im + (double)(i * fractal->s_y);
}
