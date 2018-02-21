/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 13:16:46 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/16 19:43:51 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** To animate the scene we need to
** init_act();
** set_act();
** action();
*/

void	action(t_act *act)
{
            // ft_putendlcolor("action();", MAGENTA);
	if (act->action < 0)
		return ;
	while (act)
	{
		if (act->action == 1)
			;
			// act_ellipse(act);
		else if (act->action == 2)
			act_movaxis(act);
		else if (act->action == 3)
			act_color(act->obj1);
		act = act->next;
	}
}

/*
** Add an action to the list
*/

t_act		*add_action(t_b *b, t_act act)
{
            ft_putendlcolor("add_action();", MAGENTA);
	t_act	*l;

	if (!b)
		return (NULL);
	if (!(l = b->act))
	{
		b->act = (t_act *)malloc(sizeof(t_act));
		*(b->act) = act;
		b->act->next = NULL;
		return (b->act);
	}
	while (l->next)
		l = l->next;
	l->next = (t_act *)malloc(sizeof(t_act));
	l = l->next;
	*l = act;
	l->next = NULL;
	return (l);
}


/*
** Move inline of the axe defined and between min and max
*/

void	act_movaxis(t_act *act)
{
	double tmp;
	// t_v 	min;
	// t_v  	max;
	// t_v		v;

	// min = init_vect(-3.0, 0.0, 0.0);
	// max = init_vect(3.0, 0.0, 0.0);
	// v = vect_sub(max, min);
	// act->obj1->ori = vect_add(min, vect_multnb(&v, (cos(act->p) + 1.) / 2.));
	// act->p += DEG2RAD(20);
	if (act->min >= act->max)
	{
		tmp = act->min;
		act->min = act->max;
		act->max = tmp;
	}
	if (*act->axis >= act->max)
		act->p = 0;
	else if (*act->axis <= act->min)
		act->p = 1;
	if (act->p == 1)
		*act->axis += act->speed;
	else
		*act->axis -= act->speed;
}

/*
** To change the color
*/

void		act_color(t_obj *obj)
{
            // ft_putendlcolor("act_color();", MAGENTA);
	obj->tex.col.r = (double)rand() / (double)RAND_MAX;
	obj->tex.col.g = (double)rand() / (double)RAND_MAX;
	obj->tex.col.b = (double)rand() / (double)RAND_MAX;
}

/*
** Make an object turning around an other
*/

// void	act_ellipse(t_act *act)
// {
// 	double	deltaX;
// 	double	deltaY;
// 	t_v		point;

// 	point = vect_add(act->ori, init_vect(1.0, 1.0, 1.0));
// 	deltaX = vect_sub(act->ori.x, (act->ori.x + 2.0));
// 	deltaY = vect_sub(act->ori.y, (act->ori.y + 2.0));
// 	act->angle = atan2(deltaX, deltaY);
//   	act->dist = vect_dist(act->ori.x, act->ori.y, point.x, point.y);
//   	x = act->ori.x + cos(act->angle) * vect2int();
//   	y = act->ori.y + sin(act->angle) * vect2int();
//   	act->angle += M_PI / 120;
// }
