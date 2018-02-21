/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:58:32 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/21 21:27:41 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Calculate the ambiant lux
*/

t_col	calc_amb(t_b *b)
{
	return (color_mult(b->amb, color_mult(b->inter.tex.ka, b->inter.tex.col)));
}

/*
** Calculate the diffuse lux
*/

void	calc_dif(t_lux *lux, t_inter inter)
{
	double	dot;

	if ((dot = vect_dot(inter.n, lux->light)) <= 0.0)
		lux->lum_dif = init_col(0.0, 0.0, 0.0);
	else
		lux->lum_dif = color_mult(lux->dif, color_multnb(color_mult(inter.tex.kd, inter.tex.col), dot));
}

/*
** Calculate the specular lux
*/

void	calc_spe(t_lux *lux, t_inter inter, t_v to_eye)
{
	t_col	plasti;
	t_v		reflect;
	double	dot;

	reflect = vect_add(vect_multnb(&lux->light, -1), vect_multnb(&inter.n, 2 * vect_dot(lux->light, inter.n)));
	if ((dot = vect_dot(reflect, to_eye)) <= 0.0)
	{
		lux->lum_spe = init_col(0.0, 0.0, 0.0);
		return ;
	}
	plasti = color_add(color_multnb(inter.tex.col, 1 - inter.tex.plasti), init_col(inter.tex.plasti, inter.tex.plasti, inter.tex.plasti));
	lux->lum_spe = color_mult(lux->spe, color_multnb(color_mult(inter.tex.ks, plasti), pow(dot, inter.tex.rug)));
}

/*
**	Add a lux to the list
*/

t_lux		*add_lux(t_b *b, t_lux lux)
{
            ft_putendlcolor("add_lux();", MAGENTA);
	t_lux	*l;

	if (!b)
		return (NULL);
	if (!(l = b->lux))
	{
		b->lux = (t_lux *)malloc(sizeof(t_lux));
		*(b->lux) = lux;
		b->lux->id = ++b->maxid;
		b->lux->next = NULL;
		// b->lux->sph = add_sphere(b, init_sph(b->lux->ori, b->lux->dif));
		// b->lux->sph->tex.col = b->lux->dif;
		// b->lux->sph->islux = 1;
		// b->lux->sph->r = 0.2;
		return (b->lux);
	}
	while (l->next)
		l = l->next;
	l->next = (t_lux *)malloc(sizeof(t_lux));
	l = l->next;
	*l = lux;
	l->id = ++b->maxid;
	l->next = NULL;
	// l->sph = add_sphere(b, init_sph(l->ori, l->dif));
	// l->sph->tex.col = l->dif;
	// l->sph->islux = 1;
	// l->sph->r = 0.2;
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