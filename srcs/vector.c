/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 19:45:14 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/30 20:34:13 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
**	Add a vector into the list
*/

t_vl		*add_vl(t_b *b, t_vl vl)
{
	t_vl	*l;

	if (!b)
		return (NULL);
	if (!(l = b->vl))
	{
		b->vl = (t_vl *)malloc(sizeof(t_vl));
		*(b->vl) = vl;
		b->vl->next = NULL;
		return (b->vl);
	}
	while (l->next)
		l = l->next;
	l->next = (t_vl *)malloc(sizeof(t_vl));
	l = l->next;
	*l = vl;
	l->next = NULL;
	return (l);
}

/*
** Search a vector with the id
*/

t_vl	*search_vl(t_b *b, int id)
{
			ft_putendlcolor("search_vl();", MAGENTA);
	t_vl	*l;
			printf("ID SEARCH = %d\n", id);
	if (id <= 0 || !b || !b->vl)
		return (NULL);
	l = b->vl;
	printf("search = %p\n", l);
	while (l && l->id != id)
		l = l->next;
	return (l);
}