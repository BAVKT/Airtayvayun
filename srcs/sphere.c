/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:33:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/16 21:53:37 by vmercadi         ###   ########.fr       */
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
	unsigned int color;

	ori = vect_sub(ray.ori, sph.center);
	b = 2 * vect_dot(ray.dir, ori);
	c = vect_norme2(ori) - sph.r * sph.r;
	if ((delta = b * b - 4 * c) < 0)
		return (0);
	ray.t = (-b - sqrt(delta)) / 2;
	if (ray.t < 0)
		return (0);
		// printf("t = %f\n", ray.t);
		// printf("delta = %f\n", delta);
	 // printf("poney = %f\n", vect_norme2(ray2vect(ray)) / vect_norme2(ori));
ratio = 1 + vect_norme2(ray2vect(ray)) / vect_norme2(ori);
	ratio /= 2.2;
	color = ((int)((sph.color >> 16) / ratio) << 16) | ((int)(((sph.color >> 8) & 0xff) / ratio) << 8) | (int)((sph.color & 0xff) / ratio);
	// if (ratio > 2 || ratio < 1)
		return (color);
		//return ((unsigned int)((double)sph.color) / ratio * 1.5);
	// else
	// 	return ((unsigned int)((double)sph.color / vect_norme2(ray2vect(ray)) * vect_norme2(ori)));
}