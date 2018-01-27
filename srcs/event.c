/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:17:12 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/27 17:42:26 by vmercadi         ###   ########.fr       */
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
		ft_putstr("r = ");
			ft_putnbrendl(SDLK_r);
		if (event.type == SDL_QUIT || ev == SDLK_ESCAPE)
			return (0);
		else if (ev == SDLK_DOWN | ev == SDLK_UP | ev == SDLK_LEFT | ev == SDLK_RIGHT)
			ev_rotate_xy(b, ev);
		else if (ev == SDLK_w || ev == SDLK_a || ev == SDLK_s || ev == SDLK_d || ev == SDLK_KP_MINUS || ev == SDLK_KP_PLUS)
			b->cam.pos = ev_move(b , ev);
		else if (ev == SDLK_3 || ev == SDLK_4)
			ev_qualitat(b, ev);
		else if (ev == SDLK_r)
			ev_reset(b);
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
	b->aliasing = 4;
}

/*
** Event to change the qualitat
*/

void	ev_qualitat(t_b *b, int ev)
{
	if (ev == SDLK_3 && b->aliasing > 1)
		b->aliasing -= 1;
	else if (ev == SDLK_4 && b->aliasing < 100)
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

t_v		ev_move(t_b *b, int ev)
{
			ft_putendlcolor("ev_move();", MAGENTA);
	t_v tmp;

	tmp = b->cam.pos;
	if (ev == SDLK_w)
		tmp.y = b->cam.pos.y + 0.06;
	else if (ev == SDLK_s)
		tmp.y = b->cam.pos.y - 0.06;
	else if (ev == SDLK_a)
		tmp.x = b->cam.pos.x - 0.06;
	else if (ev == SDLK_d)
		tmp.x = b->cam.pos.x + 0.06;
	else if (ev == SDLK_KP_PLUS)
		tmp = vect_add(b->cam.pos, vect_multnb(&b->cam.dir, 0.1));
	else if (ev == SDLK_KP_MINUS)
		tmp = vect_sub(b->cam.pos, vect_multnb(&b->cam.dir, 0.1));
	return (tmp);
}
