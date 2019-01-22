/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gere_mouse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/18 15:08:27 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/18 17:18:18 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int  gere_mouse_move(int x, int y, t_env *e)
{
    if (e->mouse == 0)
    {
        return (0);
    }
    e->c_i = (double)((y - H_WIN / 2) / e->z);
    e->c_r = (double)((x - W_WIN / 2) / e->z);
    ft_expose(e);
    return(0);
}
int  gere_mouse(int k, int x, int y, t_env *e)
{
     (void)x;
     (void)y;
    if (k == 4 || k == 1)
    {
        e->x1 = (x / e->z + e->x1) - (x / (e->z * 1.3));
        e->y1 = (y / e->z + e->y1) - (y / (e->z * 1.3));
        e->z *= 1.3;
    }
    if (k == 5 || k == 2)
    {
		e->x1 = (x / e->z + e->x1) - (x / (e->z / 1.3));
		e->y1 = (y / e->z + e->y1) - (y / (e->z / 1.3));
		e->z /= 1.3;
    }
    ft_expose(e);
    return(0);
}