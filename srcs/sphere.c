/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 17:33:30 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/16 20:06:15 by vmercadi         ###   ########.fr       */
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
	t_v		ori;

	ori = vect_sub(ray.ori, sph.center);
		// vect_print(ray.dir);
	b = 2 * vect_dot(ray.dir, ori);
		// printf("b = %f\n", b);
	c = vect_norme2(&ori) - sph.r * sph.r;
		// printf("c = %f\n", c);
	if ((delta = b * b - 4 * c) < 0)
		return (0);
	ray.t = (-b - sqrt(delta)) / 2;
	if (ray.t < 10)
		printf("t = %f\n", ray.t);
		// printf("delta = %f\n", delta);
	return ((unsigned int)(ray.t * 1000));
}