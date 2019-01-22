/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:02:12 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/21 14:02:59 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while(e->x < W_IMG)
	{
		while (e->y < H_IMG)
		{
			e->c_r = e->x / e->z + e->x1;
			e->c_i = e->y / e->z + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && e->i < e->itmax)
			{
				e->tmp = e->z_r;
				e->z_r = (e->z_r * e->z_r - e->z_i * e->z_i) + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;	
			}
			if (e->i == e->itmax)	
			{
				e->data[(int)e->x + ((int)e->y) * W_IMG] = RED;
			}
			else
			{
				e->data[(int)e->x + ((int)e->y) * W_IMG] = e->i*GREEN/e->itmax;
			}
			e->y++;
		}
		e->x++;
		e->y = 0;
	}
	return(0);
}

int	julia(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while(e->x < W_IMG)
	{
		while (e->y < H_IMG)
		{
			e->c_i = 0.01;
			e->c_r = 0.285;
			e->z_r = e->x / e->z + e->x1;
			e->z_i = e->y / e->z + e->y1;
			e->i = 0;
			while ((e->z_r * e->z_r + e->z_i * e->z_i) < 4 && e->i < e->itmax)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;	
			}
			if (e->i == e->itmax)	
			{
				e->data[(int)e->x + (int)e->y * W_IMG] = YELLOW;
			}
			else
			{
				e->data[(int)e->x + (int)e->y * W_IMG] = e->i*GREEN/e->itmax;
			}
			e->y++;
		}
		e->x++;
		e->y = 0;
	}
	return(0);
}