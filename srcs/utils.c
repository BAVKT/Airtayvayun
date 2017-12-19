/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 20:08:33 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/19 17:19:07 by vmercadi         ###   ########.fr       */
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

	// 2 Tests avant d'aboutir a la formule en bas
	// viewPlaneUpLeft + rightVec * xIndent * x - upVec * yIndent * y;
	// b->vp.upleft + b->cam.dirright * b->vp.xi * x - b->cam.dirup * b->vp.yi * y;

	// nb = vect_normalize(vect_add(b->cam.dirup, vect_sub(vect_multnb(&vect_multnb(&b->cam.dirright,
	// 	b->vp.xi), x), vect_multnb(&vect_multnb(&b->cam.dirup, b->vp.yi), y))));

	// On calcule l'emplacement du pixel dans le viewplane
	b->vp.xi = b->vp.w / (double)b->winx;
	b->vp.yi = b->vp.h / (double)b->winy;
	tmp = vect_multnb(&b->cam.dirright, b->vp.xi);
		// ft_putendl("tmp = ");
		// vect_print(tmp);
	tmp2 = vect_multnb(&b->cam.dirup, b->vp.yi);
		// ft_putendl("tmp2 = ");
		// vect_print(tmp2);
	tmp3 = vect_add(b->vp.upleft, vect_sub(vect_multnb(&tmp, (double)px.x), vect_multnb(&tmp2, (double)px.y)));
		// ft_putendl("tmp3 = ");
		// vect_print(tmp3);
	//On dessine dans l'image
	return (tmp3);
}

/*
** Sort un vect a partir d'un ray
*/

t_v		ray2vect(t_ray ray)
{
	return (vect_add(ray.ori, vect_multnb(&ray.dir, ray.t)));
}