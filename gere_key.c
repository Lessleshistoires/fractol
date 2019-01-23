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

void	select_f1(int key, t_env *e)
{
	if (key == ESC)
		exit(1);
	if (key == ONE_PAD || key == K1_KEY)
	{
		env_init(e);
		e->frac = 1;
	}
	if (key == TWO_PAD || key == K2_KEY)
	{
		env_init(e);
		e->frac = 2;
	}
	if (key == THREE_PAD || key == K3_KEY)
	{
		env_init(e);
		e->frac = 3;
	}
	if (key == FOUR_PAD || key == K4_KEY)
	{
		env_init(e);
		e->frac = 4;
	}
}

void	select_f2(int key, t_env *e)
{
	if (key == FIVE_PAD || key == K5_KEY)
	{
		env_init(e);
		e->frac = 5;
	}
	if (key == SIX_PAD || key == K6_KEY)
	{
		env_init(e);
		e->frac = 6;
	}
	if (key == SEVEN_PAD || key == K7_KEY)
	{
		env_init(e);
		e->frac = 7;
	}
	if (key == EIGHT_PAD || key == K8_KEY)
	{
		env_init(e);
		e->frac = 8;
	}
	if (key == NINE_PAD || key == K9_KEY)
	{
		env_init(e);
		e->frac = 9;
	}
}

int		gere_key(int key, t_env *e)
{
	select_f1(key, e);
	select_f2(key, e);
	if (key == LEFT)
		e->x1 -= 1 / e->z;
	if (key == RIGHT)
		e->x1 += 1 / e->z;
	if (key == UP)
		e->y1 -= 1 / e->z;
	if (key == DOWN)
		e->y1 += 1 / e->z;
	if (key == Z)
		e->itmax += 1;
	if (key == X && e->itmax >= 0)
		e->itmax -= 1;
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
