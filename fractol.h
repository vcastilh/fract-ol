/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcastilh <vcastilh@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 07:36:36 by vcastilh          #+#    #+#             */
/*   Updated: 2022/02/16 10:30:20 by vcastilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
 # define FRACTOL_H
 # include <unistd.h>
 # include "libft.h"

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
	t_complex	max;
	t_complex	min;
}	t_fractal;

typedef	struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img;
	char	*img_addr;
}	t_mlx;

void		ft_usage(void);
void		ft_set_fractal(char **argv, t_fractal *fractal);
t_complex	ft_complex(long double re, long double im);
#endif

