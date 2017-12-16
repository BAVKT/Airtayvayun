/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 13:17:12 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/16 21:32:57 by vmercadi         ###   ########.fr       */
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
		if (event.type == SDL_QUIT)
			return (0);
		else if (ev == SDLK_DOWN | ev == SDLK_UP | ev == SDLK_LEFT | ev == SDLK_RIGHT)
			ev_rotate_xy(b, ev);
		else if (ev == SDLK_w || ev == SDLK_a | ev == SDLK_s | ev == SDLK_d)
			b->cam.pos = ev_move(b->cam.pos, ev);
	}
	return (1);
}

/*
** Event for rotating the vector
*/

void	ev_rotate_xy(t_b *b, int ev)
{
			ft_putendlcolor("ev_rotate_xy();", MAGENTA);
	int	angle;

	angle = 10.0 * M_PI / 180.0;
	if (ev == SDLK_DOWN)
		b->cam.dirup = vect_rotate_xy(b->cam.dirup, -angle);
	else if (ev == SDLK_UP)
		b->cam.dirup = vect_rotate_xy(b->cam.dirup, angle);
	else if (ev == SDLK_RIGHT)
		b->cam.dirright = vect_rotate_xy(b->cam.dirright, angle);
	else if (ev == SDLK_LEFT)
		b->cam.dirright = vect_rotate_xy(b->cam.dirright, -angle);
	b->cam.dir = vect_prod(b->cam.dirup, b->cam.dirright);
}

/*
** Moving keys : up | down | right | left
*/

t_v		ev_move(t_v v, int ev)
{
			ft_putendlcolor("ev_move();", MAGENTA);
	t_v tmp;

	tmp = v;
	if (ev == SDLK_w)
		tmp.z = v.z + 0.1;
	else if (ev == SDLK_s)
		tmp.z = v.z - 0.1;
	else if (ev == SDLK_a)
		tmp.x = v.x - 0.1;
	else if (ev == SDLK_d)
		tmp.x = v.x + 0.1;
	return (tmp);
}
