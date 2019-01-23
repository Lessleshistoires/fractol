/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:59:31 by lpelissi          #+#    #+#             */
/*   Updated: 2019/01/21 13:59:33 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


int		check(t_env *e)
{
	int i;
	char *str;
	char *tmp;

	if (!(str = (char*)malloc(sizeof(char) * 9)))
		return (0);
	str = "fractal-";
	i = 3;
	if (e->prm != 2)
	{
		ft_putstr("wrong number of param\n");
		exit(1);
	}
	if (ft_strcmp(e->name, "mandelbrot") == 0)
		e->frac = 1;
	else if (ft_strcmp(e->name, "julia") == 0)
		e->frac = 2;
	while (i <= 7)
	{
		tmp = ft_strjoin(str, ft_itoa(i));
		if (ft_strcmp(e->name, tmp) == 0)
		{
			e->frac = i;
			return (0);
		}
		i++;
	}
	if (ft_strcmp(e->name, "mandelbrot") != 0 &&
		ft_strcmp(e->name, "julia") != 0 && ft_strcmp(e->name, tmp) != 0)
	{
		ft_putstr("wrong file name\n");
		exit(1);
	}
	return (0);
}

int		main(int ac, char **av)
{
	t_env	*e;
	(void)av;
	if (!(e = (t_env*)malloc(sizeof(t_env))))
		return (0);
	e->name = av[1];
	e->frac = 1;
	e->prm = ac;
	check(e);
	ft_fractol(e);

	free(e);
	return (0);
}
