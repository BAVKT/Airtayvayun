/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:53:52 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/19 18:06:32 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Calculate the intersection between a ray and a planical plane
*/

double		calc_plane(t_ray *ray, t_plane plane)
{
	double	prod;
	t_v		n;

//t = - ( (A*X + B*Y + C*Z + D) / (A*DIR.x + B*DIR.y + C*DIR.z) )
	n = init_vect(plane.a, plane.b, plane.c);
	prod = vect_dot(n, ray->dir);
	if (!prod)
		return (0);
	else
		return ((ray->t = -(vect_dot(n, ray->ori) + plane.d) / prod));
}

/*
**	Add a plane to the list
*/

t_plane		*add_plane(t_b *b, t_plane plane)
{
	t_plane	*l;

	if (!b)
		return (NULL);
	if (!(l = b->plane))
	{
		b->plane = (t_plane *)malloc(sizeof(t_plane));
		*(b->plane) = plane;
		b->plane->id = ++b->maxid;
		b->plane->next = NULL;
		return (b->plane);
	}
	while (l->next)
		l = l->next;
	l->next = (t_plane *)malloc(sizeof(t_plane));
	l = l->next;
	*l = plane;
	l->id = ++b->maxid;
	l->next = NULL;
	return (l);
}

/*
** Search a plane with the id
*/

t_plane		*search_plane(t_b *b, int id)
{
	t_plane	*l;

	if (id <= 0 || !b)
		return (NULL);
	l = b->plane;
	while (l && l->id != id)
		l = l->next;
	if (!l)
		return (NULL);
	return (l);
}