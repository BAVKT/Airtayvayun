/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:49:31 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/27 17:49:59 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Chekc intersction of all the objects of the world and the universe and clement
*/

t_inter		*inter_obj(t_b *b, t_ray *ray)
{
			// ft_putendlcolor("inter_obj();", MAGENTA);
	int		id;
	t_sph	*sph;
	t_plane	*plane;
	t_v		dest;

	if (!b->inter)
		b->inter = (t_inter *)malloc(sizeof(t_inter));
	b->inter->min = b->max;
	if ((id = inter_sphere(b, ray)) > 0)
	{
		sph = search_sphere(b, id);
		ray->t = b->inter->min;
		b->inter->n = vect_sub(sph->center, ray2vect(*ray));
		b->inter->tex = sph->tex;
		//b->inter->to_cam ?
		return (b->inter);
	}
	else if ((id = inter_plane(b, ray)) > 0)
	{
		plane = search_plane(b, id);
		ray->t = b->inter->min;
		b->inter->n = init_vect(plane->a, plane->b, plane->c);
		b->inter->tex = plane->tex;
		dest = vect_add(ray->ori, vect_multnb(&ray->dir, ray->t));
		// printf("dest = x=%f y=%f z=%f\n", dest.x, dest.y, dest.z);
		if (fabs(dest.x - (double)((int)(dest.x))) < 0.05 && dest.x > 0)
			b->inter->tex.col = init_col(1.0, 0.0, 0.0);
		else if (fabs(dest.z - (double)((int)(dest.z))) < 0.1 && dest.z < 0)
			b->inter->tex.col = init_col(1.0, 0.0, 0.0);
		//b->inter->to_cam ?
		return (b->inter);
	}
	return (NULL);
}

/*
** Checker l'intersection avec toutes les spheres
*/

int		inter_sphere(t_b *b, t_ray *ray)
{
			// ft_putendlcolor("inter_sphere();", MAGENTA);
	t_sph			*l;
	double			t;
	unsigned int	id;

	l = b->sph;
	id = -1;
	while (l)
	{
		t = calc_sphere(ray, *l);
		if (t > 1 && t < b->inter->min && t < b->max)
		{
			b->inter->min = t;
			id = l->id;
		}
		l = l->next;
	}
	return (id);
}

/*
** Checker l'intersection avec tous les planes
*/

int		inter_plane(t_b *b, t_ray *ray)
{
			// ft_putendlcolor("inter_plane();", MAGENTA);
	t_plane			*l;
	double			t;
	int				id;

	l = b->plane;
	id = -1;
	while (l)
	{
		t = 0;
		t = calc_plane(ray, *l);
		if (t > 1 && t < b->inter->min && t < b->max)
		{
			b->inter->min = t;
			id = l->id;
		}
		l = l->next;
	}
	return (id);
}
