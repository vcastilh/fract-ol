/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:24:26 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/16 08:03:15 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		ft_usage();
	else if (ft_strncmp(argv[1], "Mandelbrot", 11) != 0
			&& (ft_strncmp(argv[1], "Julia", 6) == 0 && argc < 4))
		ft_usage();
	return (0);
}

void	ft_usage(void)
{
	write(1, "Error\n", 6);
}
