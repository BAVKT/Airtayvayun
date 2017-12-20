/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:58:32 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/20 17:30:14 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Fichier our calculer toutes les composantes differentes des lumieres
*/

/*
** Calculate the ambiant lux
*/

void	calc_amb(t_lux *lux, t_tex tex)
{
	lux->lum_amb = color_mult(lux->amb, color_mult(tex.ka, tex.col));
}

/*
** Calculate the diffuse lux
*/

void	calc_dif(t_lux *lux, t_tex tex, t_v n)
{
	lux->lum_dif = color_mult(lux->dif, color_multnb(color_mult(tex.kd, tex.col), vect_dot(lux->light, n)));
}

/*
** Calculate the specular lux
*/

void	calc_spe(t_lux *lux, t_tex tex, t_ray eye, t_v n)
{
	t_col	plasti;
	t_v		reflect;

	reflect = init_vect(0, 0, 0);
	plasti = color_add(color_multnb(tex.col, 1 - tex.plasti), init_col(tex.plasti, tex.plasti, tex.plasti));
	lux->lum_spe = color_mult(lux->spe, color_multnb(color_mult(tex.ks, plasti), pow(vect_dot(eye.dir, n), tex.rug)));
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