/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:24:26 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/21 11:05:59 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char **argv)
{
	t_fractal	fractal;

	if (argc < 2)
	{
		ft_usage();
		return (1);
	}
	else if ((ft_strncmp(argv[1], "Mandelbrot", 11) == 0 && argc == 2)
		|| ((ft_strncmp(argv[1], "Julia", 6) == 0 && argc == 4)
		&& (ft_valid_argv(argv[2]) && ft_valid_argv(argv[3]))))
	{
		ft_set_fractal(argv, &fractal);
		ft_init_mlx(&fractal);
		ft_check_fractal(&fractal);
		mlx_expose_hook(fractal.mlx.win_ptr, ft_expose_hook, &fractal);
		mlx_mouse_hook(fractal.mlx.win_ptr, ft_mouse_hook, &fractal);
		mlx_key_hook(fractal.mlx.win_ptr, ft_key_hook, &fractal);
		mlx_hook(fractal.mlx.win_ptr, 33, (1L << 17), ft_cross_hook, &fractal);
		mlx_loop(fractal.mlx.mlx_ptr);
	}
	else
	{
		ft_usage();
		return (1);
	}
	return (0);
}

void	ft_check_fractal(t_fractal *fractal)
{
	if (*fractal->name == 'M')
		ft_mandelbrot(fractal);
	else
		ft_julia(fractal);
	mlx_put_image_to_window(fractal->mlx.mlx_ptr, fractal->mlx.win_ptr,
		fractal->mlx.img, 0, 0);
}

void	ft_usage(void)
{
	char	*str;
	int		fd;

	fd = open("message.txt", O_RDONLY);
	if (fd < 0)
		return ;
	while (1)
	{
		str = ft_get_next_line(fd);
		if (!str)
			break ;
		ft_putstr_fd(str, 1);
		free(str);
	}
	close(fd);
}

int	ft_valid_argv(char *argv)
{
	int	sign;
	int	dot;

	sign = 0;
	dot = 0;
	if (!argv)
		return (1);
	while (*argv != '\0')
	{
		if (ft_isdigit(*argv))
			argv++;
		else if (*argv == '.')
		{
			dot++;
			argv++;
			if (dot > 1)
				return (0);
		}
		else if (*argv == '-')
		{	
			sign++;
			argv++;
			if (sign > 1)
				return (0);
		}
		else
			return (0);
	}
	return (1);
}
