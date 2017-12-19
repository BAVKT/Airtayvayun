/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:49:31 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/19 18:44:47 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"


/*
** Checker l'intersection avec toutes les spheres
*/

int		inter_sphere(t_sph **sph, t_ray ray, double *min)
{
	t_sph			*l;
	double			t;
	unsigned int	id;

	l = *sph;
	id = -1;
	while (l)
	{
		t = calc_sphere(ray, *l);
		if (t > 0.1 && t < *min)
		{
			*min = t;
			id = l->id;
		}
		l = l->next;
	}
	return (id);
}

/*
** Checker l'intersection avec tous les planes
*/

int		inter_plane(t_plane **plane, t_ray ray, double *min)
{
	t_plane			*l;
	double			t;
	int				id;

	l = *plane;
	id = -1;
	while (l)
	{
		t = 0;
		t = calc_plane(ray, *l);
		if (t > 0.1 && t < *min)
		{
			*min = t;
			id = l->id;
		}
		l = l->next;
	}
	return (id);
}
