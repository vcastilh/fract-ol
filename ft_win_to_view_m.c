/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_win_to_view_m.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:48:27 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/19 08:07:27 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_win_to_view_m(t_fractal *fractal, int i, int j)
{
	fractal->s_x = (fractal->max.re - fractal->min.re) / WIDTH;
	fractal->s_y = (fractal->max.im - fractal->min.im) / HEIGHT;
	fractal->c.re = fractal->min.re + (double)(j * fractal->s_x);
	fractal->c.im = fractal->min.im + (double)(i * fractal->s_y);
	fractal->z.re = 0;
	fractal->z.im = 0;
}
