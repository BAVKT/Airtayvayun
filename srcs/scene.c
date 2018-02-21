/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:22:46 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/21 21:32:00 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	scene1(t_b *b)
{
	add_lux(b, init_lux(init_vect(5.0, -5.0, -15.0), init_col(0.7, 0.7, 0.7), init_col(0.3, 0.3, 0.3)));
	b->lux->dif = init_col(0.0, 0.0, 0.8);
	b->lux->spe = init_col(0.0, 0.0, 0.8);

	add_lux(b, init_lux(init_vect(-5.0, 5.0, -5.0), init_col(0.7, 0.7, 0.7), init_col(0.3, 0.3, 0.3)));
	b->lux->next->dif = init_col(1.0, 0.0, 1.0);
	b->lux->next->spe = init_col(0.5, 0.0, 0.5);

	add_lux(b, init_lux(init_vect(0.0, 0.0, -5.0), init_col(0.7, 0.7, 0.7), init_col(0.3, 0.3, 0.3)));
	b->lux->next->next->dif = init_col(1.0, 1.0, 0.0);
	b->lux->next->next->spe = init_col(0.5, 0.5, 0.0);

	add_lux(b, init_lux(init_vect(0.0, 0.0, 5.0), init_col(0.7, 0.7, 0.7), init_col(0.3, 0.3, 0.3)));
	b->lux->next->next->dif = init_col(0.0, 1.0, 0.0);
	b->lux->next->next->spe = init_col(0.0, 1.0, 0.0);

	add_obj(b, init_sph(init_vect(2, 0, 5), init_col(0.6, 0.2, 0.2), 1.0));
	add_obj(b, init_sph(init_vect(-2, 2, 5), init_col(1.0, 1.0, 1.0), 1.0));
	add_obj(b, init_sph(init_vect(0, -2, 5), init_col(1.0, 1.0, 0.0), 1.0));
	add_obj(b, init_plane(0.0, 1.0, 0.0, 3.0, init_col(0.1, 0.0, 0.0)));
	add_action(b, init_act(b->obj, 2, 3));
	b->act->speed *= 10;
	b->act->max = 10;
	b->act->min = -10;
	// add_action(b, init_act(b->obj->next, 3, 1));
	add_action(b, init_act(b->obj->next, 2, 1));
	add_action(b, init_act(b->obj->next, 2, 2));
	add_action(b, init_act(b->obj->next, 2, 3));
	add_action(b, init_act(b->obj->next->next, 2, 1));
}

void	scene2(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, 5.0), init_col(0.7, 0.7, 0.7), init_col(0.3, 0.3, 0.3)));
	add_lux(b, init_lux(init_vect(2.0, 2.0, 5.0), init_col(0.7, 0.7, 0.7), init_col(0.3, 0.3, 0.3)));
	// b->lux->next->dif = init_col(0.0, 0.0, 1.0);
	add_obj(b, init_sph(init_vect(0, 0, 7), init_col(COL_YELLOWGREEN), 1.0));

	//add_obj(b, init_cyl(init_vect(0, 0, 5), init_col(1.0, 1.0, 1.0), init_vect(0.0, 1.0, 0.0), 1));
	//Mur fond
	add_obj(b, init_plane(0.0, 0.0, 1.0, -10.0, init_col(1.0, 0.0, 1.0)));
	//Mur droite
	add_obj(b, init_plane(0.0, 1.0, 0.0, -3.0, init_col(1.0, 0.0, 0.0)));
	//Mur gauche
	add_obj(b, init_plane(0.0, 1.0, 0.0, 3.0, init_col(0.0, 1.0, 0.0)));
	//Plafond
	add_obj(b, init_plane(1.0, 0.0, 0.0, -3.0, init_col(0.0, 0.0, 1.0)));
	//sol
	add_obj(b, init_plane(1.0, 0.0, 0.0, 3.0, init_col(0.5, 0.5, 0.5)));
	b->amb = init_col(1.0, 1.0, 1.0);
}

void	scene3(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, -25.0), init_col(0.7, 0.7, 0.7), init_col(0.3, 0.3, 0.3)));
	add_obj(b, init_sph(init_vect(0, 0, 10), init_col(1.0, 1.0, 1.0), 1.0));
	b->obj->tex.ks = init_col(0.0, 0.0, 0.0);
	b->obj->tex.kd = init_col(1.0, 1.0, 1.0);

	add_obj(b, init_sph(init_vect(2, 2, 10), init_col(0.0, 0.0, 1.0), 1.0));
	b->obj->next->tex.ks = init_col(1.0, 1.0, 1.0);
	b->obj->next->tex.kd = init_col(0.0, 0.0, 0.0);

	add_obj(b, init_sph(init_vect(0, 2, 10), init_col(1.0, 1.0, 0.0), 1.0));
	add_obj(b, init_sph(init_vect(2, 0, 10), init_col(1.0, 0.0, 0.0), 1.0));
	add_obj(b, init_plane(0.0, 1.0, 0.0, 3.0, init_col(1.0, 0.0, 0.0)));
}

void	scene4(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 1.0, 2.0), init_col(0.7, 0.7, 0.7), init_col(0.3, 0.3, 0.3)));
	add_obj(b, init_sph(init_vect(0, 0, 5), init_col(1.0, 0.0, 0.0), 1.0));
}

void	scene5(t_b *b)
{
	t_obj	*obj;
	t_act	*act;
	// t_lux	*lux;

	b->cam.pos = init_vect(0.0, 0.0, -250);

	add_lux(b, init_lux(init_vect(0.0, 3.0, -110.0), init_col(COL_YELLOWGREEN), init_col(COL_YELLOWGREEN)));
	add_lux(b, init_lux(init_vect(3.0, 1.0, -90.0), init_col(COL_BURLYWOOD), init_col(COL_BURLYWOOD)));
	add_lux(b, init_lux(init_vect(3.0, 3.0, -60.0), init_col(COL_DARKTURQUOISE), init_col(COL_DARKTURQUOISE)));
	add_lux(b, init_lux(init_vect(-3.0, -3.0, -30.0), init_col(COL_CORNFLOWERBLUE), init_col(COL_CORNFLOWERBLUE)));
	add_lux(b, init_lux(init_vect(1.0, 1.0, -150.0), init_col(COL_MISTYROSE), init_col(COL_MISTYROSE)));
	add_lux(b, init_lux(init_vect(-1.0, -1.0, 0.0), init_col(COL_NAVAJOWHITE), init_col(COL_NAVAJOWHITE)));
	add_lux(b, init_lux(init_vect(1.0, 0.0, 110.0), init_col(COL_LEMONCHIFFON), init_col(COL_LEMONCHIFFON)));
	add_lux(b, init_lux(init_vect(0.0, 1.0, 90.0), init_col(COL_MEDIUMAQUAMARINE), init_col(COL_MEDIUMAQUAMARINE)));
	add_lux(b, init_lux(init_vect(0.0, -1.0, 60.0), init_col(COL_LIGHTGOLDENRODYELLOW), init_col(COL_LIGHTGOLDENRODYELLOW)));
	add_lux(b, init_lux(init_vect(-3.0, -3.0, 30.0), init_col(COL_TOMATO), init_col(COL_TOMATO)));

	// add_lux(b, init_lux(init_vect(0.0, 3.0, -110.0), init_col(COL_WHITE), init_col(COL_WHITE)));
	// add_lux(b, init_lux(init_vect(3.0, 1.0, -90.0), init_col(COL_WHITE), init_col(COL_WHITE)));
	// add_lux(b, init_lux(init_vect(3.0, 3.0, -60.0), init_col(COL_WHITE), init_col(COL_WHITE)));
	// add_lux(b, init_lux(init_vect(-3.0, -3.0, -30.0), init_col(COL_WHITE), init_col(COL_WHITE)));
	// add_lux(b, init_lux(init_vect(1.0, 1.0, -150.0), init_col(COL_WHITE), init_col(COL_WHITE)));
	// add_lux(b, init_lux(init_vect(-1.0, -1.0, 0.0), init_col(COL_WHITE), init_col(COL_WHITE)));
	// add_lux(b, init_lux(init_vect(1.0, 0.0, 110.0), init_col(COL_WHITE), init_col(COL_WHITE)));
	// add_lux(b, init_lux(init_vect(0.0, 1.0, 90.0), init_col(COL_WHITE), init_col(COL_WHITE)));
	// add_lux(b, init_lux(init_vect(0.0, -1.0, 60.0), init_col(COL_WHITE), init_col(COL_WHITE)));
	// add_lux(b, init_lux(init_vect(-3.0, -3.0, 30.0), init_col(COL_WHITE), init_col(COL_WHITE)));
	//gauche
	add_obj(b, init_sph(init_vect(3.0, 0.0, 100), init_col(COL_CYAN), 1.0));
	obj = b->obj;
	obj->r = 0.8;
	add_action(b, init_act(obj, 2, 3));
	act = b->act;
	act->speed = 10;
	act->max = 100;
	act->min = -100;

	//centre
	add_obj(b, init_sph(init_vect(0.0, 0.0, 5), init_col(COL_WHITE), 1.0));
	obj = obj->next;
	obj->r = 1.5;

	//droite
	add_obj(b, init_sph(init_vect(-3.0, 0.0, 100), init_col(COL_CYAN), 1.0));
	obj = obj->next;
	obj->r = 0.8;
	add_action(b, init_act(obj, 2, 3));
	act = act->next;
	act->speed = 10;
	act->max = 100;
	act->min = -100;

	//haut
	add_obj(b, init_sph(init_vect(0.0, 3.0, 100), init_col(COL_CYAN), 1.0));
	obj = obj->next;
	obj->r = 0.8;
	add_action(b, init_act(obj, 2, 3));
	act = act->next;
	act->speed = 10;
	act->max = 100;
	act->min = -100;


	//bas
	add_obj(b, init_sph(init_vect(0.0, -3.0, 100), init_col(COL_CYAN), 1.0));
	obj = obj->next;
	obj->r = 0.8;
	add_action(b, init_act(obj, 2, 3));
	act = act->next;
	act->speed = 10;
	act->max = 100;
	act->min = -100;

	//Haut-gauche
	add_obj(b, init_sph(init_vect(1.5, 1.5, -100), init_col(COL_DEEPPINK), 1.0));
	obj = obj->next;
	obj->r = 0.5;
	add_action(b, init_act(obj, 2, 3));
	act = act->next;
	act->speed = 10;
	act->max = 100;
	act->min = -100;

	//Bas-droite
	add_obj(b, init_sph(init_vect(-1.5, -1.5, -100), init_col(COL_DEEPPINK), 1.0));
	obj = obj->next;
	obj->r = 0.5;
	add_action(b, init_act(obj, 2, 3));
	act = act->next;
	act->speed = 10;
	act->max = 100;
	act->min = -100;

	//Haut-droite
	add_obj(b, init_sph(init_vect(-1.5, 1.5, -100), init_col(COL_DEEPPINK), 1.0));
	obj = obj->next;
	obj->r = 0.5;
	add_action(b, init_act(obj, 2, 3));
	act = act->next;
	act->speed = 10;
	act->max = 100;
	act->min = -100;

	//Bas-gauche
	add_obj(b, init_sph(init_vect(1.5, -1.5, -100), init_col(COL_DEEPPINK), 1.0));
	obj = obj->next;
	obj->r = 0.5;
	add_action(b, init_act(obj, 2, 3));
	act = act->next;
	act->speed = 10;
	act->max = 100;
	act->min = -100;
	// add_obj(b, init_plane(0.0, 0.0, 1.0, -100.0, init_col(COL_WHITESMOKE)));
	// //Mur droite
	// add_obj(b, init_plane(0.0, 1.0, 0.0, -3.5, init_col(COL_BLUE)));
	// //Mur gauche
	// add_obj(b, init_plane(0.0, 1.0, 0.0, 3.5, init_col(COL_RED)));
	// //Plafond
	// add_obj(b, init_plane(1.0, 0.0, 0.0, -3.5, init_col(COL_YELLOW)));
	// //sol
	// add_obj(b, init_plane(1.0, 0.0, 0.0, 3.5, init_col(COL_GREEN)));

	add_obj(b, init_plane(0.0, 0.0, 1.0, -100.0, init_col(COL_WHITESMOKE)));
	//Mur droite
	add_obj(b, init_plane(0.0, 1.0, 0.0, -3.5, init_col(COL_WHITESMOKE)));
	//Mur gauche
	add_obj(b, init_plane(0.0, 1.0, 0.0, 3.5, init_col(COL_WHITESMOKE)));
	//Plafond
	add_obj(b, init_plane(1.0, 0.0, 0.0, -3.5, init_col(COL_WHITESMOKE)));
	//sol
	add_obj(b, init_plane(1.0, 0.0, 0.0, 3.5, init_col(COL_WHITESMOKE)));
	// b->amb = init_col(1.0, 1.0, 1.0);

}

void	scene6(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, 15.0), init_col(0.7, 0.7, 0.7), init_col(0.3, 0.3, 0.3)));
	b->lux->dif = init_col(0.0, 0.0, 1.0);
	b->lux->spe = init_col(0.0, 0.0, 1.0);

	add_lux(b, init_lux(init_vect(-2.0, 0.0, 10.0), init_col(0.7, 0.7, 0.7), init_col(0.3, 0.3, 0.3)));
	b->lux->next->dif = init_col(1.0, 0.0, 0.0);
	b->lux->next->spe = init_col(1.0, 0.0, 0.0);

	add_lux(b, init_lux(init_vect(2.0, 0.0, 10.0), init_col(0.7, 0.7, 0.7), init_col(0.3, 0.3, 0.3)));
	b->lux->next->next->dif = init_col(1.0, 1.0, 0.0);
	b->lux->next->next->spe = init_col(1.0, 1.0, 0.0);

	add_obj(b, init_sph(init_vect(2, 0, 10), init_col(1.0, 1.0, 1.0), 1.0));
	add_obj(b, init_plane(0.0, 1.0, 0.0, 3.0, init_col(1.0, 1.0, 1.0)));
	// add_obj(b, init_cyl(init_vect(2, 2, 3), init_col(0.0, 0.0, 1.0), init_vect(1.0, 0.0, 0.0), 1));
	// add_obj(b, init_cone(init_vect(0, 0, 5), init_col(0.0, 0.0, 1.0), init_vect(0.0, 1.0, 0.0), 1.0));
	// add_obj(b, init_cone(init_vect(0, 0, 10), init_col(0.0, 1.0, 0.0), init_vect(0.0, 1.0, 0.0), 1.0));
}

