/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:49:31 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/20 17:48:36 by cquillet         ###   ########.fr       */
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

	// ray->t = b->max;	
	if ((id = inter_all(b, ray, 1.0)) > 0)
	{
		b->inter.id = id;
		obj = search_obj(b, b->inter.id);
		if (obj->form == 1)	//Plan
		{
			b->inter.n = init_vect(obj->a, obj->b, obj->c);
		}
		else if (obj->form == 2)	//Sphere
		{
			b->inter.n = vect_sub(ray2vect(*ray), obj->ori);
		}
		else if (obj->form == 3)	//Cylindre
		{
			dest = vect_multnb(&obj->h, vect_dot(vect_sub(ray2vect(*ray), obj->ori), obj->h) / vect_norme2(obj->h));
			b->inter.n = vect_sub(dest, vect_sub(ray2vect(*ray), obj->ori));
		}
		else if (obj->form == 4)	//Cone
		{
			dest = vect_multnb(&obj->h, vect_dot(ray2vect(*ray), obj->h) / vect_norme2(obj->h));
			b->inter.n = vect_sub(vect_sub(ray2vect(*ray), obj->ori), dest);	
		}
		if (vect_dot(b->inter.n, ray->dir) > 0.0)
			b->inter.n = vect_multnb(&b->inter.n, -1);
		b->inter.tex = obj->tex;
	}
	return (ray->t);
}

/*
** Check intersction of all the objects of the world and the universe and not clement
*/

int	inter_obj_lux(t_b *b, t_ray *to_light)
{
			// ft_putendlcolor("inter_obj_lux();", MAGENTA);
	to_light->t = 1.0;
	return (inter_all(b, to_light, 0.001));
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
		t = b->max;
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
