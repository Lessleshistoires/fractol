/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:02:12 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/21 14:02:59 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


/*
mandelbrot's
*/
int	fractal3(t_env *e)
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
				e->tmp = pow((e->z_r * e->z_r + e->z_i * e->z_i), e->pow/2) *
                cos(e->pow * atan2(e->z_r,e->z_i)) + e->c_r;
                e->z_r = pow((e->z_r * e->z_r + e->z_i * e->z_i), e->pow/2) *
                sin(e->pow * atan2(e->z_r,e->z_i)) + e->c_i;
                e->z_i = e->tmp;
				/* 
				* modifier z_r pour d'autre fractale ex: z_r = tan(z_r * z_r - z_i * z_i) + c_r; 
				*/
                //e->z_r = pow(e->z_r , e->pow);
				//e->z_r = cos(e->z_r * e->z_r + e->z_i * e->z_i) / e->c_r ;
				//e->z_i = (2 * e->z_i * e->tmp + e->c_i);
               
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

int	fractal4(t_env *e)
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
			e->zrsqr = e->z_r * e->z_r;
			e->zisqr = e->z_i * e->z_i;
			e->i = 0;
			while (e->zrsqr + e->zisqr <= 4.0 && e->i < e->itmax)
			{
				e->z_i = e->z_r * e->z_i;
				e->z_i += e->z_i; // Multiply by two
				e->z_i += e->c_i;
				e->z_r = e->zrsqr - e->zisqr + e->c_r;
				e->zrsqr = e->z_r * e->z_r;
				e->zisqr = e->z_i * e->z_i;
				e->i++;
			}
			if (e->i == e->itmax)	
			{
				e->data[(int)e->x + ((int)e->y) * W_IMG] = PINK;
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

/*
julia's
*/

int	fractal5(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while(e->x < W_IMG)
	{
		while (e->y < H_IMG)
		{
        	//e->c_i = 0.1;
	        //e->c_r = -0.75;
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

int	fractal6(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while(e->x < W_IMG)
	{
		while (e->y < H_IMG)
		{
        	//e->c_i = 0.1;
	        //e->c_r = -0.75;
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
			else
			{
				e->data[(int)e->x + (int)e->y * W_IMG] = e->i*CYAN/e->itmax;
			}
			e->y++;
		}
		e->x++;
		e->y = 0;
	}
	return(0);
}

int	fractal7(t_env *e)
{
	e->x = 0;
	e->y = 0;
	while(e->x < W_IMG)
	{
		while (e->y < H_IMG)
		{
        	//e->c_i = 0.1;
	        //e->c_r = -0.75;
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
			else
			{
				e->data[(int)e->x + (int)e->y * W_IMG] = e->i*BLUE/e->itmax;
			}
			e->y++;
		}
		e->x++;
		e->y = 0;
	}
	return(0);
}