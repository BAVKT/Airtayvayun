/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 20:02:11 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/17 21:11:27 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
**	Add an obj to the list
*/

t_obj	*add_obj(t_b *b, t_obj obj)
{
			ft_putendlcolor("add_obj();", MAGENTA);
	t_obj	*l;

	if (!b)
		return (NULL);
	if (!(l = b->obj))
	{
		b->obj = (t_obj *)malloc(sizeof(t_obj));
		*(b->obj) = obj;
		b->obj->id = ++b->maxid;
		b->obj->next = NULL;
		b->vl = add_vl(b, init_vl(b->obj->ori, b->obj->id));
		return (b->obj);
	}
	while (l->next)
		l = l->next;
	l->next = (t_obj *)malloc(sizeof(t_obj));
	l = l->next;
	*l = obj;
	l->id = ++b->maxid;
	l->next = NULL;
	b->vl = add_vl(b, init_vl(l->ori, l->id));
	return (l);
}

/*
** Search an obj in the list
*/

t_obj	*search_obj(t_b *b, int id)
{
			// ft_putendlcolor("search_obj();", MAGENTA);
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

/*
** To delete a selected object
*/

void	delete_obj(t_b *b, int id)
{
			ft_putendlcolor("delete_obj();", MAGENTA);
	t_obj	*obj;
	t_obj	*obj2;

	if ((obj = search_obj(b, id - 1)))
	{
		if (obj->next->next)
			obj2 = obj->next->next;
		else
			obj2 = NULL;
		free(obj->next);
		obj->next = NULL;
		obj->next = obj2;
	}
	else if (!(obj = search_obj(b, id)))
		return ;
	else
	{
		if (obj->next)
			obj2 = obj->next;
		else
			obj2 = NULL;
		free(obj);
		obj = NULL;
		b->obj = obj2;
	}
}











































