/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:37:29 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/21 04:38:25 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_color(int t)
{
	int	r;
	int	g;
	int	b;
	double	norm_t;

	norm_t = normalize(t);
	r = (int)(9 * (1 - norm_t) * pow(norm_t, 3) * 150);
	g = (int)(15 * pow((1 - norm_t), 2) * pow(norm_t, 2) * 255);
	b = (int)(8.5 * pow((1 - norm_t), 3) * norm_t * 80);
	return ((int)norm_t << 24 | r << 16 | g << 8 | b);
}

double	normalize(int t)
{
	double res;

	res = (double)t / (double)MAX_ITER;
	return (res);
}
