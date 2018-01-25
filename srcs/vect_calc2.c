/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_calc2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:37:05 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/19 18:06:31 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Add value to a vector
*/

t_v		vect_addnb(t_v *v, double nb)
{
			// ft_putendlcolor("vect_addnb();", MAGENTA);
	t_v		c;

	c.x = v->x + nb;
	c.y = v->y + nb;
	c.z = v->z + nb;
	return (c);
}

/*
** Subtract value nb to the vector
*/

t_v		vect_subnb(t_v *v, double nb)
{
			// ft_putendlcolor("vect_subnb();", MAGENTA);
	t_v		c;

	c.x = v->x - nb;
	c.y = v->y - nb;
	c.z = v->z - nb;
	return (c);
}

/*
** Multiply a vector by nb
*/

t_v		vect_multnb(t_v *v, double nb)
{
			// ft_putendlcolor("vect_multnb();", MAGENTA);
	t_v		c;

	c.x = v->x * nb;
	c.y = v->y * nb;
	c.z = v->z * nb;
	return (c);
}