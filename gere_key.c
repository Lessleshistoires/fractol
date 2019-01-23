/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:08:27 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/18 17:18:18 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"




int	gere_key(int key, t_env *e)
{
		/* all */
	if (key == ESC)
		exit(1);
/* zoom */
/*
	if (key == MORE)
	{
        e->x1 = (x / e->z + e->x1) - (x / (e->z * 1.3));
		e->y1 = (y / e->z + e->y1) - (y / (e->z * 1.3));
		e->z *= 1.3;
	}
	if (key == LESS)
	{
		e->x1 = (x / e->z + e->x1) - (x / (e->z / 1.3));
		e->y1 = (y / e->z + e->y1) - (y / (e->z / 1.3));
		e->z /= 1.3;
	}
*/
/* choix */
	if (key == ONE_PAD)
	{
		env_init(e);
		e->frac = 1;
	}
	if (key == TWO_PAD)
	{
		env_init(e);
		e->frac = 2;
	}
	if (key == THREE_PAD)
	{
		env_init(e);
		e->frac = 3;
	}			
	if (key == FOUR_PAD)
	{
		env_init(e);
		e->frac = 4;
	}
	if (key == FIVE_PAD)
	{
		env_init(e);
		e->frac = 5;
	}		
	if (key == SIX_PAD)
	{
		env_init(e);
		e->frac = 6;
	}			
		if (key == SEVEN_PAD)
	{
		env_init(e);
		e->frac = 7;
	}				
/* move */
	if (key == LEFT)
		e->x1 -= 0.01;
	if (key == RIGHT)
		e->x1 += 0.01;
	if (key == UP)
		e->y1 -= 0.01;
	if (key == DOWN)
		e->y1 += 0.01;
/* iterations */
	if (key == Z)
		e->itmax += 1;
	if (key == X && e->itmax >= 0)
		e->itmax -= 1;
/*multibrot*/
	if (key == O)
		e->pow += 1;
	if (key == P)
		e->pow -= 1;
	
	if (key == I)
		env_init(e);
	if (key == M)
		e->mouse = (e->mouse + 1) % 2;
	ft_expose(e);
	return (0);
}
