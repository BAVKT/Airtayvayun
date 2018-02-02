/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_calc1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:03:13 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/27 17:35:40 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Produit vectoriel (pour trouver un des 3 vecteur manquant)
** Aussi appelé cross product
*/

t_v		vect_prod(t_v a, t_v b)
{
	t_v	c;

	c.x = a.y * b.z - a.z * b.y;
	c.y = -(a.x * b.z - a.z * b.x);
	c.z = a.x * b.y - a.y * b.x;
	return (c);
}

/*
** Add two vectors
*/

t_v		vect_add(t_v a, t_v b)
{
	t_v	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

/*
** Subtract 2 vectors
*/

t_v		vect_sub(t_v a, t_v b)
{
	t_v	c;

	c.x = a.x - b.x;
	c.y = a.y - b.y;
	c.z = a.z - b.z;
	return (c);
}

/*
** Dot product (produit scalaire)
*/

double		vect_dot(t_v a, t_v b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}
