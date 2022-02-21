/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:36:36 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/21 10:59:34 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# define WIDTH 500
# define HEIGHT 500
# define IMG_WIDTH 500
# define IMG_HEIGHT 500
# define MAX_ITER 80
# define DIVERGENCE 3
# define KEYPRESS 2
# define ESC 65307
# define ZOOM_IN 5
# define ZOOM_OUT 4 
# include <unistd.h>
# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <fcntl.h>

typedef struct s_complex
{
	long double		re;
	long double		im;
	unsigned int	mdl;
}	t_complex;

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	int		bpp;
	int		endian;
	int		line_size;
	char	*img_addr;
}	t_mlx;

typedef struct s_fractal
{
	t_mlx		mlx;
	t_complex	c;
	t_complex	z;
	t_complex	pow;
	t_complex	max;
	t_complex	min;
	t_complex	delta;
	char		*name;
	int			i;
	int			j;
	long double	s_x;
	long double	s_y;
}	t_fractal;

typedef struct s_scale
{
	long double	x_ratio;
	long double	y_ratio;
	t_complex	new_delta;
}	t_scale;

void		ft_usage(void);
void		ft_set_fractal(char **argv, t_fractal *fractal);
t_complex	ft_complex(long double re, long double im);
void		ft_init_mlx(t_fractal *fractal);
void		ft_mandelbrot(t_fractal *fractal);
void		ft_julia(t_fractal *fractal);
void		ft_win_to_view_m(t_fractal *fractal, int i, int j);
void		ft_win_to_view_j(t_fractal *fractal, int i, int j);
int			ft_color(int t);
void		ft_pixel_to_image(t_fractal *fractal, int i, int j, int clr);
int			ft_key_hook(int key, t_fractal *fractal);
int			ft_expose_hook(t_fractal *fractal);
void		ft_zoom(int key, int x, int y, t_fractal *fractal);
int			ft_mouse_hook(int key, int x, int y, t_fractal *fractal);
void		ft_check_fractal(t_fractal *fractal);
int			ft_cross_hook(t_fractal *fractal);
#endif
