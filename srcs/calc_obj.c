/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:05:58 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/02 21:26:33 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Calculate the intersection between a ray and a spherical sphere
*/

double		calc_sphere(t_ray *ray, t_obj sph, double min)
{
	double	ret;
	t_v		ori;

	ori = vect_sub(ray->ori, sph.ori);
	ret = solve_equation(min, vect_norme2(ray->dir), 2 * vect_dot(ray->dir, ori), vect_norme2(ori) - sph.r * sph.r);
	return (ret);
}

/*
** Calculate the intersection between a ray and a planical plane
*/

double		calc_plane(t_ray *ray, t_obj plane, double min)
{
	double	prod;
	double	r;
	t_v		n;

	//t = - ( (A*X + B*Y + C*Z + D) / (A*DIR.x + B*DIR.y + C*DIR.z) )
	n = init_vect(plane.a, plane.b, plane.c);
	prod = vect_dot(n, ray->dir);
	if (!prod)
		return (-1.);
	r = -(vect_dot(n, ray->ori) + plane.d) / prod;
	if (r < min)
		return (-1.);
	return (r);
}

/*
** Calculate the intersection between a ray and a conerical cone
*/

double		calc_cone(t_ray *ray, t_obj cone, double min)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_v		ori;

	ori = vect_sub(ray->ori, cone.ori);
	d = vect_dot(ray->dir, cone.h);
	a = vect_norme2(ray->dir) - (d * d) / vect_norme2(cone.h) * (1 - tan(cone.angle) * tan(cone.angle));
	b = 2 * (vect_dot(ray->ori, ray->dir) - vect_dot(ray->ori, cone.h) * d / vect_norme2(cone.h) * (1 - tan(cone.angle) * tan(cone.angle)));
	c = vect_norme2(ray->ori) - d * d / vect_norme2(cone.h) * (1 - tan(cone.angle) * tan(cone.angle));
	return (solve_equation(min, a, b, c));
}

/*
** Calulate the intersection for cylindre
*/

double		calc_cyl(t_ray *ray, t_obj cyl, double min)
{
	double	a;
	double	b;
	double	c;
	double	d;
	t_v		ori;

	ori = vect_sub(ray->ori, cyl.ori);
	d = vect_dot(ray->dir, cyl.h);
	a = vect_norme2(ray->dir) - (d * d) / vect_norme2(cyl.h);
	b = 2 * (vect_dot(ray->ori, ray->dir) - vect_dot(ray->ori, cyl.h) * d / vect_norme2(cyl.h));
	c = vect_norme2(ray->ori) - d * d / vect_norme2(cyl.h) - cyl.r * cyl.r;
	return (solve_equation(min, a, b, c));
}
