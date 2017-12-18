/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:33:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/18 20:06:14 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Calculate the intersection between a ray and a spherical sphere
*/

unsigned int	calc_sphere(t_ray ray, t_sph sph)
{
	double	b;
	double	c;
	double	delta;
	double	ratio;
	t_v		ori;

	ori = vect_sub(ray.ori, sph.center);
	b = 2 * vect_dot(ray.dir, ori);
	c = vect_norme2(ori) - sph.r * sph.r;
	if ((delta = b * b - 4 * c) < 0)
		return (0);
	ray.t = (-b - sqrt(delta)) / 2;
	if (ray.t < 0)
		return (0);
	ratio = 1 + vect_norme2(ray2vect(ray)) / vect_norme2(ori);
	ratio /= 1.2;
	return (sph.color = ((int)((sph.color >> 16) / ratio) << 16)
	| ((int)(((sph.color >> 8) & 0xff) / ratio) << 8)
	| (int)((sph.color & 0xff) / ratio));
}