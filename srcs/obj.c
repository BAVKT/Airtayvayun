/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:02:11 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/02 21:40:15 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
**	Add an obj to the list
*/

t_obj	*add_obj(t_b *b, t_obj obj)
{
	t_obj	*l;

	if (!b)
		return (NULL);
	if (!(l = b->obj))
	{
		b->obj = (t_obj *)malloc(sizeof(t_obj));
		*(b->obj) = obj;
		b->obj->id = ++b->maxid;
		b->obj->next = NULL;
		return (b->obj);
	}
	while (l->next)
		l = l->next;
	l->next = (t_obj *)malloc(sizeof(t_obj));
	l = l->next;
	*l = obj;
	l->id = ++b->maxid;
	l->next = NULL;
	return (l);
}

/*
** Search an obj in the list
*/

t_obj	*search_obj(t_b *b, int id)
{
	t_obj	*l;

	if (id <= 0 || !b)
		return (NULL);
	l = b->obj;
	while (l && l->id != id)
		l = l->next;
	if (!l)
		return (NULL);
	return (l);
}
