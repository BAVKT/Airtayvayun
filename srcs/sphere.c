/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:33:30 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/19 18:06:31 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Calculate the intersection between a ray and a spherical sphere
*/

double		calc_sphere(t_ray *ray, t_sph sph)
{
	double	b;
	double	c;
	double	delta;
	t_v		ori;

	ori = vect_sub(ray->ori, sph.center);
	b = 2 * vect_dot(ray->dir, ori);
	c = vect_norme2(ori) - sph.r * sph.r;
	if ((delta = b * b - 4 * c) < 0)
		return (0);
	ray->t = (-b - sqrt(delta)) / 2;
	if (ray->t < 0)
		return (0);
	return (ray->t);
}

/*
**	Add a sphericla sphere to the list
*/

t_sph		*add_sphere(t_b *b, t_sph sph)
{
	t_sph	*l;

	if (!b)
		return (NULL);
	if (!(l = b->sph))
	{
		b->sph = (t_sph *)malloc(sizeof(t_sph));
		*(b->sph) = sph;
		b->sph->id = ++b->maxid;
		b->sph->next = NULL;
		return (b->sph);
	}
	while (l->next)
		l = l->next;
	l->next = (t_sph *)malloc(sizeof(t_sph));
	l = l->next;
	*l = sph;
	l->id = ++b->maxid;
	l->next = NULL;
	return (l);
}

/*
** Search a spherical sphere with the id
*/

t_sph	*search_sphere(t_b *b, int id)
{
	t_sph	*l;

	if (id <= 0 || !b)
		return (NULL);
	l = b->sph;
	while (l && l->id != id)
		l = l->next;
	if (!l)
		return (NULL);
	return (l);
}