/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:16:46 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/02 17:21:36 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** To animate the scene
*/

void	action(t_act *act)
{
	act->obj1 = obj1;
	act->obj2 = obj2;
	if (act->action == 1)
		act_ellipse(act);
	else
		return (0);
}

/*
** Make an object turning around an other
*/

void	act_ellipse(t_act *act)
{
	double	deltaX;
	double	deltaY;
	t_v		point;

	point = vect_add(act->ori, init_vect(1.0, 1.0, 1.0));
	deltaX = vect_sub(act->ori.x, (act->ori.x + 2.0));
	deltaY = vect_sub(act->ori.y, (act->ori.y + 2.0));
	act->angle = atan2(deltaX, deltaY);
  	act->dist = vect_dist(act->ori.x, act->ori.y, point.x, point.y);
  	x = act->ori.x + cos(act->angle) * vect2int();
  	y = act->ori.y + sin(act->angle) * vect2int();
  	act->angle += M_PI / 120;
}
