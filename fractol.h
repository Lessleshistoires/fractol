/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:59:11 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/21 13:59:17 by lpelissi         ###   ########.fr       */
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
		/* main */
	char		*name;
	int			prm;
	int			ctr;
		/* mlx */
	int			frac;
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			sline;
	int			end;
		/* draw */

	double		x1;
	double		y1;
	double		z;
	int 		itmax;
	int			pow;
	double 		x;
	double 		y;
	double 		c_r;
	double 		c_i;
	double 		z_r;
	double 		z_i;
	double 		i;
	double 		tmp;
	int 		mouse;
}				t_env;


int ft_fractol(t_env *e);
void	env_init(t_env *e);
int	mandelbrot(t_env *e);
int	julia(t_env *e);
int	otherbrot(t_env *e);
int	cos_j(t_env *e);
int	tan_j(t_env *e);
int	gere_key(int key, t_env *e);
int gere_mouse(int k, int x, int y, t_env *e);
int  gere_mouse_move(int x, int y, t_env *e);
int	ft_expose(t_env *e);


#endif
