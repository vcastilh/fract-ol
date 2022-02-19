/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:36:36 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/19 08:55:37 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
 # define FRACTOL_H
 # define WIDTH 500
 # define HEIGHT 500
 # define IMG_WIDTH 500
 # define IMG_HEIGHT 500
 # define MAX_ITER 2000
 # define DIVERGENCE 3
 # include <unistd.h>
 # include "libft.h"
 # include "mlx.h"
 # include <math.h>

typedef	struct	s_complex
{
	long double		re;
	long double		im;
	unsigned int	mdl;
}	t_complex;

typedef	struct	s_fractal
{
	char		*name;
	t_complex	c;
	t_complex	z;
	t_complex	pow;
	t_complex	max;
	t_complex	min;
	long double	s_x;
	long double s_y;
}	t_fractal;

typedef	struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		bpp;
	int		endian;
	int		line_size;
	char	*img_addr;
}	t_mlx;

void		ft_usage(void);
void		ft_set_fractal(char **argv, t_fractal *fractal);
t_complex	ft_complex(long double re, long double im);
void		ft_init_mlx(t_mlx *mlx, t_fractal *fractal);
void		ft_mandelbrot(t_fractal *fractal, t_mlx *mlx);
void		ft_julia(t_fractal *fractal, t_mlx *mlx);
void		ft_win_to_view_m(t_fractal *fractal, int i, int j);
void		ft_win_to_view_j(t_fractal *fractal, int i, int j);
int			ft_color(int t);
void		ft_pixel_to_image(t_mlx *mlx, int i, int j, int clr);
#endif
