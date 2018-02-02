/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:00:15 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/30 19:45:30 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Sort le carré de la norme du vecteur
*/

double		vect_norme2(t_v v)
{
			// ft_putendlcolor("vect_norme2();", MAGENTA);
	return((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

/*
** Sort la norme du vecteur
*/

double		vect_norme(t_v v)
{
			// ft_putendlcolor("vect_norme();", MAGENTA);
	return(sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z)));
}

/*
** Normalize a vector
*/

void		vect_normalize(t_v *v)
{
			// ft_putendlcolor("vect_normalize();", MAGENTA);
	double n;

	n = vect_norme(*v);
	v->x /= n;
	v->y /= n;
	v->z /= n;
}

/*
** La précession = autour de l'axe Oz, fait passer de (O,x,y,z) au référentiel (O,u,v,z) (en bleu).
** La nutation = autour de l'axe Ou (ligne des nœuds), fait passer de (O,u,v,z) à (O,u,w,z’) (en vert).
** La rotation propre ou giration = autour de l'axe Oz’, fait passer de (O,u,w,z’) au référentiel lié au solide (O,x’,y’,z’) (en rouge).
**	i + s * q + (1-c) * q*q
*/

t_v		vect_rotate(t_v v, double angle, t_v axe)
{
			// ft_putendlcolor("vect_rotate_xy();", MAGENTA);
	t_v 		tmp;
	t_matrice	q;
	t_matrice	r;

	q = init_matrice();
	r = init_matrice();
	q.data[0][1] = -axe.z;
	q.data[0][2] = axe.y;
	q.data[1][0] = axe.z;
	q.data[1][2] = -axe.x;
	q.data[2][0] = -axe.y;
	q.data[2][1] = axe.x;
	r.data[0][0] = 1;
	r.data[1][1] = 1;
	r.data[2][2] = 1;
	r = matrice_add(r, matrice_multnb(q, sin(angle)));
	r = matrice_add(r, matrice_multnb(matrice_mult(q, q), 1 - cos(angle)));
	tmp = matrice_multvect(r, v);
	return (tmp);
}

/*
** Print the vector values
*/

void		vect_print(t_v v)
{
	printf("x = %f | y = %f | z = %f\n", v.x, v.y, v.z);
}