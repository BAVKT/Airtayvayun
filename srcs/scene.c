/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:22:46 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/02 21:37:46 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	scene1(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, 15.0)));
	b->lux->dif = init_col(0.0, 0.0, 1.0);
	b->lux->spe = init_col(0.0, 0.0, 1.0);

	add_lux(b, init_lux(init_vect(-2.0, 0.0, 10.0)));
	b->lux->next->dif = init_col(1.0, 0.0, 0.0);
	b->lux->next->spe = init_col(1.0, 0.0, 0.0);

	add_lux(b, init_lux(init_vect(2.0, 0.0, 10.0)));
	b->lux->next->next->dif = init_col(1.0, 1.0, 0.0);
	b->lux->next->next->spe = init_col(1.0, 1.0, 0.0);

	add_obj(b, init_sph(init_vect(0, 0, 10), init_col(1.0, 1.0, 1.0)));
	add_obj(b, init_plane(0.0, 1.0, 0.0, 3.0, init_col(0.7, 0.0, 0.0)));
}

void	scene2(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, 5.0)));
	add_lux(b, init_lux(init_vect(2.0, 2.0, 5.0)));
	b->lux->next->dif = init_col(0.0, 0.0, 1.0);
	b->lux->next->spe = init_col(0.0, 0.0, 1.0);
	add_lux(b, init_lux(init_vect(-2.0, -2.0, -15.0)));
	b->lux->next->next->dif = init_col(1.0, 0.0, 0.0);
	b->lux->next->next->spe = init_col(1.0, 0.0, 0.0);
	add_obj(b, init_sph(init_vect(0, 0, 10), init_col(1.0, 1.0, 0.0)));
	add_obj(b, init_sph(init_vect(2, 2, 10), init_col(0.0, 0.0, 1.0)));
	add_obj(b, init_sph(init_vect(0, 2, 10), init_col(0.0, 1.0, 0.0)));
	add_obj(b, init_sph(init_vect(2, 0, 10), init_col(1.0, 0.0, 0.0)));
	add_obj(b, init_sph(init_vect(0, 4, 10), init_col(1.0, 1.0, 1.0)));
	add_obj(b, init_sph(init_vect(4, 0, 10), init_col(1.0, 1.0, 1.0)));
	add_obj(b, init_sph(init_vect(6, 0, 10), init_col(1.0, 1.0, 1.0)));

	//Mur fond
	add_obj(b, init_plane(0.0, 0.0, 1.0, -10.0, init_col(1.0, 0.0, 1.0)));
	//Mur droite
	add_obj(b, init_plane(1.0, 0.0, 0.0, 5.0, init_col(1.0, 0.0, 0.0)));
	//Mur gauche
	add_obj(b, init_plane(1.0, 0.0, 0.0, -5.0, init_col(0.0, 1.0, 0.0)));
	//Plafond
	add_obj(b, init_plane(0.0, 1.0, 0.0, -5.0, init_col(0.0, 0.0, 1.0)));
	//sol
	add_obj(b, init_plane(0.0, 1.0, 0.0, 5.0, init_col(0.5, 0.5, 0.5)));
}

void	scene3(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, 25.0)));
	add_obj(b, init_sph(init_vect(0, 0, 10), init_col(1.0, 1.0, 1.0)));
	b->obj->tex.ks = init_col(0.0, 0.0, 0.0);
	b->obj->tex.kd = init_col(1.0, 1.0, 1.0);
	add_obj(b, init_sph(init_vect(2, 2, 10), init_col(0.0, 0.0, 1.0)));
	b->obj->next->tex.ks = init_col(1.0, 1.0, 1.0);
	b->obj->next->tex.kd = init_col(0.0, 0.0, 0.0);
	add_obj(b, init_sph(init_vect(0, 2, 10), init_col(1.0, 1.0, 0.0)));
	add_obj(b, init_sph(init_vect(2, 0, 10), init_col(1.0, 0.0, 0.0)));
	add_obj(b, init_plane(0.0, 1.0, 0.0, 3.0, init_col(1.0, 0.0, 0.0)));
}

void	scene4(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, 25.0)));
	add_obj(b, init_sph(init_vect(0, 0, 10), init_col(1.0, 1.0, 1.0)));
	add_obj(b, init_plane(0.0, 1.0, 0.0, 3.0, init_col(1.0, 0.0, 0.0)));
	add_obj(b, init_plane(0.0, 0.0, 1.0, -15.0, init_col(0.4, 0.0, 0.0)));
	add_obj(b, init_plane(1.0, 0.0, 0.0, 5.0, init_col(0.4, 0.0, 0.0)));
	add_obj(b, init_plane(1.0, 0.0, 0.0, -5.0, init_col(0.4, 0.0, 0.0)));
}

void	scene5(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, 15.0)));
	b->lux->dif = init_col(0.0, 0.0, 1.0);
	b->lux->spe = init_col(0.0, 0.0, 1.0);

	add_lux(b, init_lux(init_vect(-2.0, 0.0, 10.0)));
	b->lux->next->dif = init_col(1.0, 0.0, 0.0);
	b->lux->next->spe = init_col(1.0, 0.0, 0.0);

	add_lux(b, init_lux(init_vect(2.0, 0.0, 10.0)));
	b->lux->next->next->dif = init_col(1.0, 1.0, 0.0);
	b->lux->next->next->spe = init_col(1.0, 1.0, 0.0);

	add_obj(b, init_sph(init_vect(0, 0, 10), init_col(1.0, 1.0, 1.0)));
	add_obj(b, init_plane(0.0, 1.0, 0.0, 3.0, init_col(1.0, 1.0, 1.0)));
	//Mur fond
	add_obj(b, init_plane(0.0, 0.0, 1.0, -10.0, init_col(1.0, 0.0, 1.0)));
}

void	scene6(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, 15.0)));
	b->lux->dif = init_col(0.0, 0.0, 1.0);
	b->lux->spe = init_col(0.0, 0.0, 1.0);

	add_lux(b, init_lux(init_vect(-2.0, 0.0, 10.0)));
	b->lux->next->dif = init_col(1.0, 0.0, 0.0);
	b->lux->next->spe = init_col(1.0, 0.0, 0.0);

	add_lux(b, init_lux(init_vect(2.0, 0.0, 10.0)));
	b->lux->next->next->dif = init_col(1.0, 1.0, 0.0);
	b->lux->next->next->spe = init_col(1.0, 1.0, 0.0);

	add_obj(b, init_sph(init_vect(2, 0, 10), init_col(1.0, 1.0, 1.0)));
	add_obj(b, init_plane(0.0, 1.0, 0.0, 3.0, init_col(1.0, 1.0, 1.0)));
	// add_obj(b, init_cyl(init_vect(2, 2, 3), init_col(0.0, 0.0, 1.0), init_vect(1.0, 0.0, 0.0), 1));
	// add_obj(b, init_cone(init_vect(0, 0, 5), init_col(0.0, 0.0, 1.0), init_vect(0.0, 1.0, 0.0)));
	// add_obj(b, init_cone(init_vect(0, 0, 10), init_col(0.0, 1.0, 0.0), init_vect(0.0, 1.0, 0.0)));
}
