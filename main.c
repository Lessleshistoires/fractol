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
	if (e->prm != 2)
	{
		ft_putstr("wrong number of param\n");
		return (0);
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
