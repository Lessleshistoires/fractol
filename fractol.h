/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:59:11 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/23 18:04:25 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/includes/libft.h"
# include "minilibx_macos/mlx.h"
# include "color.h"
# include "keyboard.h"
# include <math.h>
# include <stdio.h>

# define W_WIN 1100
# define H_WIN 1100
# define W_IMG 1100
# define H_IMG 1100
# define NAME "Fractol by Lpelissi"
# define MASK 1L<<8

typedef struct	s_env
{
	char		*name;
	int			prm;
	int			ctr;
	int			frac;
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			sline;
	int			end;
	double		x1;
	double		y1;
	double		z;
	int			itmax;
	int			pow;
	double		x;
	double		y;
	double		c_r;
	double		c_i;
	double		z_r;
	double		z_i;
	double		zrsqr;
	double		zisqr;
	double		i;
	double		tmp;
	int			mouse;
}				t_env;
int				ft_fractol(t_env *e);
void			env_init(t_env *e);
int				mandelbrot(t_env *e);
int				julia(t_env *e);
int				fractal3(t_env *e);
int				fractal4(t_env *e);
int				fractal5(t_env *e);
int				fractal6(t_env *e);
int				fractal7(t_env *e);
int				fractal8(t_env *e);
int				fractal9(t_env *e);
int				gere_key(int key, t_env *e);
int				gere_mouse(int k, int x, int y, t_env *e);
int				gere_mouse_move(int x, int y, t_env *e);
int				ft_expose(t_env *e);

#endif
