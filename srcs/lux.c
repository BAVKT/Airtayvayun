/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 18:58:32 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/19 20:43:09 by vmercadi         ###   ########.fr       */
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
	lux->lum_amb = color_mult(lux->amb, color_mult(lux->ka, tex.col));
}

/*
** Calculate the diffuse lux
*/

void	calc_dif(t_lux *lux, t_tex tex, t_v n)
{
	lux->lum_dif = color_mult(lux->dif, color_multnb(color_mult(lux->kd, tex.col)), vect_dot(lux->light, n));
}

/*
** Calculate the specular lux
*/

void	calc_spe(t_lux *lux, t_tex tex, t_ray eye, t_v n)
{
	t_col	plasti;
	t_v		reflect;

	reflect = init_vect();
	plasti = col_add(col_multnb(tex.col, 1 - tex.plasti), init_col(tex.plasti, tex.plasti, tex.plasti));
	lux->lum_spe = color_mult(lux->spe, color_multnb(color_mult(lux->ks, plasti)), pow(vect_dot(eye.dir, n), tex.rug));
}
