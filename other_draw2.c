/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_draw2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:02:12 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/23 17:56:55 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** mandelbrot's
** tanh
*/

void	calc_f9(t_env *e)
{
	e->c_r = e->x / e->z + e->x1;
	e->c_i = e->y / e->z + e->y1;
	e->z_r = 0;
	e->z_i = 0;
	e->i = 0;
	while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && e->i < e->itmax)
	{
		e->tmp = e->z_r;
		e->z_r = tanh(e->z_r * e->z_r - e->z_i * e->z_i) + e->c_r / 1.5;
		e->z_i = 2 * e->z_i * e->tmp + e->c_i / 1.5;
		e->i++;
	}
	if (e->i == e->itmax)
		e->data[(int)e->x + ((int)e->y) * W_IMG] = RED;
}

int		fractal9(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while (e->x < W_IMG)
	{
		while (e->y < H_IMG)
		{
			calc_f9(e);
			if (e->i != e->itmax)
			{
				e->data[(int)e->x + ((int)e->y) * W_IMG] =
				e->i * GREEN / e->itmax;
			}
			e->y++;
		}
		e->x++;
		e->y = 0;
	}
	return (0);
}
