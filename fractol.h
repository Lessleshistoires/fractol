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

typedef struct	s_env
{
		/* main */
	int			prm;
	int			ctr;
		/* mlx */
	void		*mlx;
	void		*win;
	void		*img;
	int			*data;
	int			bpp;
	int			sline;
	int			end;
		/* draw */

	double		x1;
	double 		x2;

	double		y1;
	double 		y2;

	double 		img_x;
	double 		img_y;

	int			z;
	int 		itmax;

	double 		x;
	double 		y;
	double 		c_r;
	double 		c_i;
	double 		z_r;
	double 		z_i;
	double 		i;
	double 		tmp;
}				t_env;


int ft_fractol(t_env *e);
void	env_init(t_env *e);
int	mandelbrot(t_env *e);
int	julia(t_env *e);
int	otherbrot(t_env *e);
int	gere_key(int key, t_env *e);
int	ft_expose(t_env *e);


#endif
