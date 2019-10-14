/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 13:59:31 by lpelissi          #+#    #+#             */
/*   Updated: 2019/10/09 16:17:15 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		check(t_env *e, char *tmp)
{
	if (ft_strcmp(e->name, "mandelbrot") != 0 &&
		ft_strcmp(e->name, "julia") != 0 && ft_strcmp(e->name, tmp) != 0)
	{
		ft_putstr(" wrong file call\n only calls allowed:\n mandelbrot\n julia\n fractal-3\n fractal-4\n fracatl-5\n fractal-6\n fractal-7\n fractal-8\n fractal-9\n");
		exit(1);
	}
	return (0);
}

int		name(t_env *e)
{
	int		i;
	char	*str;
	char	*tmp;
	char	*c;

	str = "fractal-";
	i = 3;
	while (i <= 9)
	{
		c = ft_itoa(i);
		tmp = ft_strjoin(str, c);
		free(c);
		if (ft_strcmp(e->name, tmp) == 0)
		{
			e->frac = i;
			return (0);
		}
		if (i >= 3 && i <= 8)
			free(tmp);
		i++;
	}
	check(e, tmp);
	free(tmp);
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
	if (e->prm != 2)
	{
		ft_putstr("wrong number of parameters\n");
		exit(1);
	}
	if (ft_strcmp(e->name, "mandelbrot") == 0)
		e->frac = 1;
	else if (ft_strcmp(e->name, "julia") == 0)
		e->frac = 2;
	name(e);
	ft_fractol(e);
	free(e);
	return (0);
}
