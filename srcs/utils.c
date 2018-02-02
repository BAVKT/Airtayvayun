/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:08:33 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/02 19:33:29 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Return the pos of the pixel in the viewplane
*/

t_v		draw_pixelvp(t_b *b, t_px px)
{
            // ft_putendlcolor("draw_pixelvp();", MAGENTA);
	t_v	tmp;
	t_v tmp2;
	t_v tmp3;

	b->vp.xi = b->vp.w / (double)b->winx;
	b->vp.yi = b->vp.h / (double)b->winy;
	tmp = vect_multnb(&b->cam.dirright, b->vp.xi);
	tmp2 = vect_multnb(&b->cam.dirup, b->vp.yi);
	b->vp.upleft = vect_sub(vect_add(b->cam.pos, vect_add(vect_multnb(&b->cam.dir, b->vp.dist),
				vect_multnb(&b->cam.dirup, b->vp.h / 2))), vect_multnb(&b->cam.dirright, b->vp.w / 2));
	tmp3 = vect_add(b->vp.upleft, vect_sub(vect_multnb(&tmp, (double)px.x), vect_multnb(&tmp2, (double)px.y)));
	return (tmp3);
}

/*
** Sort un vect a partir d'un ray
*/

t_v		ray2vect(t_ray ray)
{
	return (vect_add(ray.ori, vect_multnb(&ray.dir, ray.t)));
}

/*
** Solve any 1st and 2nd degree equation
*/

double		solve_equation(double min, double a, double b, double c)
{
	double	ret;
	double	delta;

	if (a == 0)
		return (-c / b);
	if (((delta = b * b - 4 * a * c) < 0))
		return (-1.);
	if (delta == 0)
		return (-b / 2 * a);
	ret = (-b - sqrt(delta)) / 2 / a;
	if (ret > min)
		return (ret);
	else
		return((-b + sqrt(delta)) / 2 / a);
}

/*
**
*/

// t_px	pos2px(t_b *b, t_v v)
// {
// 	t_px	px;
// 	t_ray	ray;

// 	ray.ori = v;
// 	ray.dir = vect_sub(v, b->cam.pos);
// 	vect_normalize(&ray.dir);
// 	ray.y = b->dist;
// 	v = ray2vect(ray);
// 	px.x = ;
// 	t_v	tmp;
// 	t_v tmp2;
// 	t_v tmp3;

// 	b->vp.xi = b->vp.w / (double)b->winx;
// 	b->vp.yi = b->vp.h / (double)b->winy;
// 	tmp = vect_multnb(&b->cam.dirright, b->vp.xi * (double)px.x);
// 	tmp2 = vect_multnb(&b->cam.dirup, b->vp.yi * (double)px.y);
// 	b->vp.upleft = vect_sub(vect_add(b->cam.pos, vect_add(vect_multnb(&b->cam.dir, b->vp.dist),
// 				vect_multnb(&b->cam.dirup, b->vp.h / 2))), vect_multnb(&b->cam.dirright, b->vp.w / 2));
// 	tmp3 = vect_add(b->vp.upleft, vect_sub(tmp, tmp2));
// 	return (px);
// }






































