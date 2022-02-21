/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_fractal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 18:57:23 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/21 04:02:13 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_set_fractal(char **argv, t_fractal *fractal)
{
	fractal->max = ft_complex(2, 2);
	fractal->min = ft_complex(-2, -2);
	if (argv[1][0] == 'M')
	{
		fractal->name = argv[1];
	}
	else if (argv[1][0] == 'J')
	{
		fractal->name = argv[1];
		fractal->c = ft_complex(ft_atold(argv[2]), ft_atold(argv[3]));
	}
}
