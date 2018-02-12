/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:49:31 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/06 18:13:40 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Chekc intersction of all the objects of the world and the universe and clement
*/

double	inter_obj(t_b *b, t_ray *ray)
{
			// ft_putendlcolor("inter_obj();", MAGENTA);
	t_obj	*obj;
	t_v		dest;
	int		id;

	ray->t = b->max;
	//Sphere
	if ((id = inter_all(b, ray, 1.0)) > 0)
	{
		b->inter.id = id;
		obj = search_obj(b, b->inter.id);
		// if (!obj->islux)
		// {
			b->inter.n = vect_sub(ray2vect(*ray), obj->ori);
			if (vect_dot(b->inter.n, ray->dir) > 0.0)
				b->inter.n = vect_multnb(&b->inter.n, -1);
			b->inter.tex = obj->tex;
		// }
	}
	//Plan
	if ((id = inter_all(b, ray, 1.0)) > 0)
	{
		b->inter.id = id;
		obj = search_obj(b, b->inter.id);
		b->inter.n = init_vect(obj->a, obj->b, obj->c);
		if (vect_dot(b->inter.n, ray->dir) > 0.0)
			b->inter.n = vect_multnb(&b->inter.n, -1);
		b->inter.tex = obj->tex;
		dest = vect_add(ray->ori, vect_multnb(&ray->dir, ray->t));
	}
	//Cylindre
	if ((id = inter_all(b, ray, 1.0)) > 0)
	{
		b->inter.id = id;
		obj = search_obj(b, b->inter.id);
		dest = vect_multnb(&obj->h, vect_dot(ray2vect(*ray), obj->h) / vect_norme2(obj->h));
		b->inter.n = vect_sub(vect_sub(ray2vect(*ray), obj->ori), dest);
		if (vect_dot(b->inter.n, ray->dir) > 0.0)
			b->inter.n = vect_multnb(&b->inter.n, -1);
		b->inter.tex = obj->tex;
		dest = vect_add(ray->ori, vect_multnb(&ray->dir, ray->t));
	}
	//Cone
	if ((id = inter_all(b, ray, 1.0)) > 0)
	{
		b->inter.id = id;
		obj = search_obj(b, b->inter.id);
		dest = vect_multnb(&obj->h, vect_dot(ray2vect(*ray), obj->h) / vect_norme2(obj->h));
		b->inter.n = vect_sub(vect_sub(ray2vect(*ray), obj->ori), dest);
		if (vect_dot(b->inter.n, ray->dir) > 0.0)
			b->inter.n = vect_multnb(&b->inter.n, -1);
		b->inter.tex = obj->tex;
		dest = vect_add(ray->ori, vect_multnb(&ray->dir, ray->t));
	}
	return (ray->t);
}

/*
** Check intersction of all the objects of the world and the universe and not clement
*/

double	inter_obj_lux(t_b *b, t_ray *ray)
{
			// ft_putendlcolor("inter_obj_lux();", MAGENTA);
	ray->t = 1.0;
	inter_all(b, ray, 0.0);
	return (ray->t);
}

/*
** inter for everything
*/

int		inter_all(t_b *b, t_ray *ray, double min)
{
	t_obj			*l;
	double			t;
	unsigned int	id;

	l = b->obj;
	id = -1;
	while (l)
	{
		if (l->form == 1)
			t = calc_plane(ray, *l, min);
		else if (l->form == 2)
			t = calc_sphere(ray, *l, min);
		else if (l->form == 3)
			t = calc_cyl(ray, *l, min);
		else if (l->form == 4)
			t = calc_cone(ray, *l, min);
		if (t > min && t < ray->t)
		{
			ray->t = t;
			id = l->id;
		}
		l = l->next;
	}
	return (id);
}
