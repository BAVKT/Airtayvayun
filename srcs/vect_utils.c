/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 19:00:15 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/16 18:35:01 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Sort le carré de la norme du vecteur
*/

double		vect_norme2(t_v *v)
{
			// ft_putendlcolor("vect_norme2();", MAGENTA);
	return((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
}

/*
** Sort la norme du vecteur
*/

double		vect_norme(t_v *v)
{
			// ft_putendlcolor("vect_norme();", MAGENTA);
	return(sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z)));
}

/*
** Normalize a vector
*/

void		vect_normalize(t_v *v)
{
			// ft_putendlcolor("vect_normalize();", MAGENTA);
	double n;

	n = vect_norme(v);
	v->x /= n;
	v->y /= n;
	v->z /= n;
}

/*
** Rotate the x and y of the vector
*/

t_v		vect_rotate_xy(t_v v, double angle)
{
			// ft_putendlcolor("vect_rotate_xy();", MAGENTA);
	t_v tmp;

	tmp.x = v.x * cos(angle) - v.y * sin(angle);
	tmp.y = v.x * sin(angle) + v.y * cos(angle);
	return (tmp);
}

/*
** Vect init
*/

t_v		vect_init(double x, double y, double z)
{
	t_v	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}


/*
** Print the vector values
*/

void		vect_print(t_v v)
{
	printf("x = %f | y = %f | z = %f\n", v.x, v.y, v.z);
}