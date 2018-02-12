/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:17:12 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/12 16:42:33 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Catch and throw the events
*/

int		event(t_b *b)
{
	SDL_Event	event;
	int			ev;

	while (SDL_PollEvent(&event))
	{
		ev = event.key.keysym.sym;
		ft_putstr("k = ");
			ft_putnbrendl(ev);
		if (event.type == SDL_QUIT || ev == SDLK_ESCAPE)
			return (0);
		else if (ev == SDLK_DOWN | ev == SDLK_UP | ev == SDLK_LEFT | ev == SDLK_RIGHT)
			ev_rotate_xy(b, ev);
		else if (ev == SDLK_w || ev == SDLK_a || ev == SDLK_s || ev == SDLK_d ||
				ev == SDLK_KP_MINUS || ev == SDLK_KP_PLUS)
			ev_move_cam(b, ev);
		else if (ev == SDLK_i || ev == SDLK_j || ev == SDLK_k || ev == SDLK_l
			|| ev == SDLK_u || ev == SDLK_o || ev == SDLK_DELETE || ev == SDLK_KP_0
			|| ev == SDLK_KP_1 || ev == SDLK_KP_2 || ev == SDLK_KP_3 || ev == SDLK_KP_4 || ev == SDLK_KP_5)
			event_obj(b, ev);
		else if (ev == SDLK_3 || ev == SDLK_4)
			ev_qualitat(b, ev);
		else if (ev == SDLK_r)
			ev_reset(b);
		else if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			ev_mouse(b);
		else if (ev == SDLK_SPACE)
			b->act->action *= -1;
		else if (ev == SDLK_f)
			to_fdf(b, "map.fdf");
	}
	return (1);
}

/*
** Return to basic values
*/

void	ev_reset(t_b *b)
{
			ft_putendlcolor("ev_reset();", MAGENTA);
	init_cam(&b->cam);
	b->lux->ori = init_vect(0.0, 0.0, 25.0);
	b->aliasing = 4;
}

/*
** Event to change the qualitat
*/

void	ev_qualitat(t_b *b, int ev)
{
	if (ev == SDLK_3 && b->aliasing > 1)
		b->aliasing -= 1;
	else if (ev == SDLK_4 && b->aliasing <= b->winy / 4 && b->aliasing <= b->winx / 4)
		b->aliasing += 1;
}

/*
** Event for rotating the vector
*/

void	ev_rotate_xy(t_b *b, int ev)
{
			ft_putendlcolor("ev_rotate_xy();", MAGENTA);
	double	angle;

	angle = 3.0 * M_PI / 180.0;

	// if (ev == SDLK_DOWN)
	// 	b->cam.dirup = vect_rotate_xy(b->cam.dirup, -angle);
	// else if (ev == SDLK_UP)
	// 	b->cam.dirup = vect_rotate_xy(b->cam.dirup, angle);
	// else if (ev == SDLK_RIGHT)
	// 	b->cam.dirright = vect_rotate_xy(b->cam.dirright, angle);
	// else if (ev == SDLK_LEFT)
	// 	b->cam.dirright = vect_rotate_xy(b->cam.dirright, -angle);
	// b->cam.dir = vect_prod(b->cam.dirup, b->cam.dirright);
	if (ev == SDLK_DOWN)
	{
		b->cam.dir = vect_rotate(b->cam.dir, -angle, b->cam.dirright);
		b->cam.dirup = vect_rotate(b->cam.dirup, -angle, b->cam.dirright);
		// b->cam.dirright = vect_prod(b->cam.dir, b->cam.dirup);
	}
	else if (ev == SDLK_UP)
	{
		b->cam.dir = vect_rotate(b->cam.dir, angle, b->cam.dirright);
		b->cam.dirup = vect_rotate(b->cam.dirup, angle, b->cam.dirright);
		// b->cam.dirright = vect_prod(b->cam.dir, b->cam.dirup);
	}
	else if (ev == SDLK_RIGHT)
	{
		b->cam.dir = vect_rotate(b->cam.dir, angle, b->cam.dirup);
		b->cam.dirright = vect_rotate(b->cam.dirup, angle, b->cam.dirup);
		// b->cam.dirup = vect_prod(b->cam.dirright, b->cam.dir);
	}
	else if (ev == SDLK_LEFT)
	{
		b->cam.dir = vect_rotate(b->cam.dir, -angle, b->cam.dirup);
		b->cam.dirright = vect_rotate(b->cam.dirup, -angle, b->cam.dirup);
		// b->cam.dirup = vect_prod(b->cam.dirright, b->cam.dir);
	}
	// b->cam.dir = vect_prod(b->cam.dirup, b->cam.dirright);
}


/*
** Moving keys : up | down | right | left
*/

void		ev_move_cam(t_b *b, int ev)
{
			ft_putendlcolor("ev_move_cam();", MAGENTA);
	if (ev == SDLK_w)
		b->cam.pos = vect_add(b->cam.pos, vect_multnb(&b->cam.dirup, 0.5));
	else if (ev == SDLK_s)
		b->cam.pos = vect_sub(b->cam.pos, vect_multnb(&b->cam.dirup, 0.5));
	else if (ev == SDLK_a)
		b->cam.pos = vect_sub(b->cam.pos, vect_multnb(&b->cam.dirright, 0.5));
	else if (ev == SDLK_d)
		b->cam.pos = vect_add(b->cam.pos, vect_multnb(&b->cam.dirright, 0.5));
	else if (ev == SDLK_KP_PLUS)
		b->cam.pos = vect_add(b->cam.pos, vect_multnb(&b->cam.dir, 2));
	else if (ev == SDLK_KP_MINUS)
		b->cam.pos = vect_sub(b->cam.pos, vect_multnb(&b->cam.dir, 2));
}

























