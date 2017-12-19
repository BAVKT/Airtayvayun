/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 17:53:52 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/19 18:57:53 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Calculate the intersection between a ray and a planical plane
*/

double		calc_plane(t_ray ray, t_plane plane)
{
	double	prod;
	t_v		n;

//t = - ( (A*X + B*Y + C*Z + D) / (A*DIR.x + B*DIR.y + C*DIR.z) )
	n = init_vect(plane.a, plane.b, plane.c);
	prod = vect_dot(n, ray.dir);
	if (!prod)
		return (0);
	else
		return ((ray.t = -(vect_dot(n, ray.ori) + plane.d) / prod));
}
