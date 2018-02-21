/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_obj.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cquillet <cquillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 14:55:30 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/19 18:49:27 by cquillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Event for objects
**
** 0 = Lumiere
** 1 = Sphere
** 2 = Plan
** 3 = Cylindre
** 4 = Cone
*/

void	event_obj(t_b *b, int ev)
{
	t_px	px;

	SDL_GetMouseState(&px.x, &px.y);
	if (ev == SDLK_i || ev == SDLK_j || ev == SDLK_k || ev == SDLK_l
	|| ev == SDLK_u || ev == SDLK_o)
		ev_move_obj(b, ev);
	else if (ev == SDLK_DELETE)
		delete_obj(b, b->id);
	else if (ev == SDLK_KP_0)
		add_lux(b, init_lux(init_vect(b->cam.pos.x, b->cam.pos.y, b->cam.pos.z + 5), init_col(0.7, 0.7, 0.7), init_col(0.3, 0.3, 0.3)));
	else if (ev == SDLK_KP_1)
		add_obj(b, init_sph(init_vect(b->cam.pos.x, b->cam.pos.y, b->cam.pos.z + 100.0), init_col(1.0, 1.0, 1.0), 1));
	else if (ev == SDLK_KP_2)
		add_obj(b, init_plane(b->cam.pos.x, b->cam.pos.y, b->cam.pos.z + 5.0, 5.0, init_col(1.0, 1.0, 1.0)));
	else if (ev == SDLK_KP_3)
		add_obj(b, init_cyl(init_vect(b->cam.pos.x, b->cam.pos.y, b->cam.pos.z + 5), init_col(1.0, 1.0, 1.0), init_vect(1.0, 1.0, 1.0), 1));
	else if (ev == SDLK_KP_4)
		add_obj(b, init_cone(init_vect(b->cam.pos.x, b->cam.pos.y, b->cam.pos.z + 5), init_col(1.0, 1.0, 1.0), init_vect(0.0, 1.0, 0.0), 1));
}

/*
** Moving for obj keys : up = i | down = k | right = l | left = j
**							forward = u | backward = o
*/

void	ev_move_obj(t_b *b, int ev)
{
			ft_putendlcolor("ev_move_obj();", MAGENTA);
	t_obj	*obj;

			printf("b id = %d\n", b->id);
	if (!(obj = search_obj(b, b->id)))
		return (ev_move_lum(b, ev));
	if (ev == SDLK_i)
		obj->ori.x += 0.5;
	else if (ev == SDLK_k)
		obj->ori.x -= 0.5;
	else if (ev == SDLK_l)
		obj->ori.y += 0.5;
	else if (ev == SDLK_j)
		obj->ori.y -= 0.5;
	else if (ev == SDLK_u)
		obj->ori.z -= 2.0;
	else if (ev == SDLK_o)
		obj->ori.z += 2.0;
}

/*
** Moving for lux keys : up = i | down = k | right = l | left = j
**							forward = u | backward = o
*/

void	ev_move_lum(t_b *b, int ev)
{
			ft_putendlcolor("ev_move_lux();", MAGENTA);
	t_lux	*lux;

			printf("b id = %d\n", b->id);
	if (!(lux = search_lux(b, b->id)))
		return ;
	if (ev == SDLK_i)
		lux->ori.x += 0.1;
	else if (ev == SDLK_k)
		lux->ori.x -= 0.1;
	else if (ev == SDLK_l)
		lux->ori.y += 0.1;
	else if (ev == SDLK_j)
		lux->ori.y -= 0.1;
	else if (ev == SDLK_u)
		lux->ori.z -= 2.0;
	else if (ev == SDLK_o)
		lux->ori.z += 2.0;
}

void	ev_mouse(t_b *b)
{
			ft_putendlcolor("ev_mouse();", MAGENTA);
	t_px px;

	SDL_GetMouseState(&px.x, &px.y);
	b->id = b->tab_px[px.y][px.x].id;
	printf("id = %d\n", b->tab_px[px.y][px.x].id);
}











































