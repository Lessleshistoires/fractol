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
	if (key == LESS)
		e->z *= 1.1;
	if (key == MORE)
		e->z /= 1.1;
/* move */
	if (key == RIGHT)
		e->x1 -= 0.1;
	if (key == LEFT)
		e->x1 += 0.1;
	if (key == DOWN)
		e->y1 -= 0.1;
	if (key == UP)
		e->y1 += 0.1;
/* iterations */
	if (key == Z)
		e->itmax += 2;
	if (key == X && e->itmax >= 0)
		e->itmax -= 2;

		/* julia */
/* motifs */
	if (key == C)
		 e->c_i -= 0.1;
	if (key == V)
		e->c_i += 0.1;		
	if (key == B)
		 e->c_r -= 0.1;
	if (key == N)
		e->c_r += 0.1;

	if (key == O)
	{
		 e->x1 -= 0.1;
		 e->x2 += 0.1;
	}
	if (key == P)
	{
		 e->y1 -= 0.1;
		 e->y2 += 0.1;
	}
	if (key == K)
	{
		 e->y1 += 0.1;
		 e->y2 -= 0.1;
	}
	if (key == L)
	{
		 e->y1 += 0.1;
		 e->y2 -= 0.1;
	}

	ft_expose(e);
	return (0);
}
