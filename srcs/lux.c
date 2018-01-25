/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:58:32 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/19 18:06:33 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Fichier our calculer toutes les composantes differentes des lumieres
*/

/*
** Calculate the ambiant lux
*/

t_col	calc_amb(t_b *b)
{
	return (color_mult(b->amb, color_mult(b->inter->tex.ka, b->inter->tex.col)));
}

/*
** Calculate the diffuse lux
*/

void	calc_dif(t_lux *lux, t_inter inter)
{
	lux->lum_dif = color_mult(lux->dif, color_multnb(color_mult(inter.tex.kd, inter.tex.col), vect_dot(lux->light, inter.n)));
}

/*
** Calculate the specular lux
*/

void	calc_spe(t_lux *lux, t_inter inter, t_v eye)
{
	t_col	plasti;
	t_v		reflect;

	reflect = init_vect(0, 0, 0);
	plasti = color_add(color_multnb(inter.tex.col, 1 - inter.tex.plasti), init_col(inter.tex.plasti, inter.tex.plasti, inter.tex.plasti));
	lux->lum_spe = color_mult(lux->spe, color_multnb(color_mult(inter.tex.ks, plasti), pow(vect_dot(eye, inter.n), inter.tex.rug)));
}

/*
**	Add a lux to the list
*/

t_lux		*add_lux(t_b *b, t_lux lux)
{
	t_lux	*l;

	if (!b)
		return (NULL);
	if (!(l = b->lux))
	{
		b->lux = (t_lux *)malloc(sizeof(t_lux));
		*(b->lux) = lux;
		b->lux->id = ++b->maxid;
		b->lux->next = NULL;
		return (b->lux);
	}
	while (l->next)
		l = l->next;
	l->next = (t_lux *)malloc(sizeof(t_lux));
	l = l->next;
	*l = lux;
	l->id = ++b->maxid;
	l->next = NULL;
	return (l);
}

/*
** Search a lux with the id
*/

t_lux	*search_lux(t_b *b, int id)
{
	t_lux	*l;

	if (id <= 0 || !b)
		return (NULL);
	l = b->lux;
	while (l && l->id != id)
		l = l->next;
	if (!l)
		return (NULL);
	return (l);
}