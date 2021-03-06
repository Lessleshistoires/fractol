/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:44:36 by lpelissi          #+#    #+#             */
/*   Updated: 2018/11/17 13:00:04 by lpelissi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int n;
	int p;

	n = 0;
	p = 0;
	while (s1[n] != '\0')
		n++;
	while (s2[p] != '\0')
	{
		s1[n] = s2[p];
		n++;
		p++;
	}
	s1[n] = '\0';
	return (s1);
}
