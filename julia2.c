/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:02:12 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/23 17:55:23 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
** julia's
** sin
*/

void	calc_f7(t_env *e)
{
	e->z_r = e->x / e->z + e->x1;
	e->z_i = e->y / e->z + e->y1;
	e->i = 0;
	while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && e->i < e->itmax)
	{
		e->tmp = e->z_r;
		e->z_r = sin(e->z_r * e->z_r - e->z_i * e->z_i + e->c_r);
		e->z_i = 2 * e->z_i * e->tmp + e->c_i;
		e->i++;
	}
	if (e->i == e->itmax)
	{
		e->data[(int)e->x + (int)e->y * W_IMG] = RED;
	}
}

int		fractal7(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while (e->x < W_IMG)
	{
		while (e->y < H_IMG)
		{
			calc_f7(e);
			if (e->i != e->itmax)
			{
				e->data[(int)e->x + (int)e->y * W_IMG] = e->i * BLUE / e->itmax;
			}
			e->y++;
		}
		e->x++;
		e->y = 0;
	}
	return (0);
}

/*
** julia's
** fabs
*/

void	calc_f8(t_env *e)
{
	e->z_r = e->x / e->z + e->x1;
	e->z_i = e->y / e->z + e->y1;
	e->i = 0;
	while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && e->i < e->itmax)
	{
		e->tmp = e->z_r;
		e->z_r = fabs(e->z_r * e->z_r - e->z_i * e->z_i + e->c_r);
		e->z_i = 2 * e->z_i * e->tmp + e->c_i;
		e->i++;
	}
	if (e->i == e->itmax)
	{
		e->data[(int)e->x + (int)e->y * W_IMG] = BLUE;
	}
}

int		fractal8(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while (e->x < W_IMG)
	{
		while (e->y < H_IMG)
		{
			calc_f8(e);
			if (e->i != e->itmax)
			{
				e->data[(int)e->x + (int)e->y * W_IMG] = e->i * RED / e->itmax;
			}
			e->y++;
		}
		e->x++;
		e->y = 0;
	}
	return (0);
}
