/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:49:31 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/19 18:03:54 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Chekc intersction of all the objects of the world and the universe and clement
*/

t_inter		*inter_obj(t_b *b, t_ray *ray)
{
	int		id;
			// ft_putendlcolor("inter_obj();", MAGENTA);
	t_sph	*sph;
	t_plane	*plane;
	t_v		dest;

	//printf("tata\n");
	if (!b->inter)
		b->inter = (t_inter *)malloc(sizeof(t_inter));
	b->inter->min = 1000;
	//printf("toto\n");
	if ((id = inter_sphere(&b->sph, ray, &b->inter->min)) > 0)
	{
		sph = search_sphere(b, id);
		ray->t = b->inter->min;
		b->inter->n = vect_sub(sph->center, ray2vect(*ray));
		b->inter->tex = sph->tex;
		//b->inter->to_cam ?
		return (b->inter);
	}
	else if ((id = inter_plane(&b->plane, ray, &b->inter->min)) > 0)
	{
		plane = search_plane(b, id);
		ray->t = b->inter->min;
		b->inter->n = init_vect(plane->a, plane->b, plane->c);
		b->inter->tex = plane->tex;
		dest = vect_add(ray->ori, vect_multnb(&ray->dir, ray->t));
		// printf("dest = x=%f y=%f z=%f\n", dest.x, dest.y, dest.z);
		if (fabs(dest.x - (double)((int)(dest.x))) < 0.05)
			b->inter->tex.col = init_col(1.0, 0.0, 0.0);
		// else if (fabs(dest.y - (double)((int)(dest.y))) < 0.0001)
		// 	b->inter->tex.col = init_col(1.0, 0.0, 0.0);
		else if (fabs(dest.z - (double)((int)(dest.z))) < 0.1)
			b->inter->tex.col = init_col(1.0, 0.0, 0.0);
		//b->inter->to_cam ?
		return (b->inter);
	}
	return (NULL);
}

/*
** Checker l'intersection avec toutes les spheres
*/

int		inter_sphere(t_sph **sph, t_ray *ray, double *min)
{
			// ft_putendlcolor("inter_sphere();", MAGENTA);
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

int		inter_plane(t_plane **plane, t_ray *ray, double *min)
{
			// ft_putendlcolor("inter_plane();", MAGENTA);
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
