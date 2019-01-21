/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fractol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 14:02:44 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/21 14:02:46 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_expose(t_env *e)
{
	e->img = mlx_new_image(e->mlx, W_IMG, H_IMG);
	e->data = (int*)mlx_get_data_addr(e->img, &e->bpp, &e->sline, &e->end);

	//mandelbrot(e);
	//julia(e);
	otherbrot(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	mlx_destroy_image(e->mlx, e->img);
	return (0);
}

int ft_fractol(t_env *e)
{
	e->mlx = mlx_init(e);
	env_init(e);
	e->win = mlx_new_window(e->mlx, W_WIN, H_WIN, NAME);
	mlx_key_hook(e->win, gere_key, e);
	mlx_expose_hook(e->win, ft_expose, e);
	mlx_loop(e->mlx);
	return (0);
}
