/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:02:12 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/23 17:51:40 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** julia's
** cos
*/

void	calc_f5(t_env *e)
{
	e->z_r = e->x / e->z + e->x1;
	e->z_i = e->y / e->z + e->y1;
	e->i = 0;
	while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && e->i < e->itmax)
	{
		e->tmp = e->z_r;
		e->z_r = cos(e->z_r * e->z_r - e->z_i * e->z_i + e->c_r);
		e->z_i = 2 * e->z_i * e->tmp + e->c_i;
		e->i++;
	}
	if (e->i == e->itmax)
	{
		e->data[(int)e->x + (int)e->y * W_IMG] = YELLOW;
	}
}

int		fractal5(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while (e->x < W_IMG)
	{
		while (e->y < H_IMG)
		{
			calc_f5(e);
			if (e->i != e->itmax)
				e->data[(int)e->x + (int)e->y * W_IMG] =
					e->i * GREEN / e->itmax;
			e->y++;
		}
		e->x++;
		e->y = 0;
	}
	return (0);
}

/*
** julia's
** tan
*/

void	calc_f6(t_env *e)
{
	e->z_r = e->x / e->z + e->x1;
	e->z_i = e->y / e->z + e->y1;
	e->i = 0;
	while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && e->i < e->itmax)
	{
		e->tmp = e->z_r;
		e->z_r = tan(e->z_r * e->z_r - e->z_i * e->z_i + e->c_r);
		e->z_i = 2 * e->z_i * e->tmp + e->c_i;
		e->i++;
	}
	if (e->i == e->itmax)
	{
		e->data[(int)e->x + (int)e->y * W_IMG] = PINK;
	}
}

int		fractal6(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while (e->x < W_IMG)
	{
		while (e->y < H_IMG)
		{
			calc_f6(e);
			if (e->i != e->itmax)
				e->data[(int)e->x + (int)e->y * W_IMG] = e->i * CYAN / e->itmax;
			e->y++;
		}
		e->x++;
		e->y = 0;
	}
	return (0);
}
