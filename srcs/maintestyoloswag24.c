/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintestyoloswag24.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 20:56:51 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/18 16:32:21 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"
		#include <stdio.h>

int		main(int ac, char **av)
{
	t_b		b;

	if (ac != 2)
	{
		ft_putendl("Need 1 arg");
		exit(0);
	}
	parse_main(&b, av[1]);
	while (b.pars.v->next)
	{
		printf("%f", b.pars.v)
		b.pars.v = b.pars.v->next;
	}
	return (0);
}