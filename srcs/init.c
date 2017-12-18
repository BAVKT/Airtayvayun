/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:12:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/18 20:06:07 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Init the base struct
*/

void	init_b(t_b *b)
{
            ft_putendlcolor("init_b();", MAGENTA);
	b->win = NULL;
	b->winx = 640;
	b->winy = 480;
	init_cam(&b->cam);
	init_vp(b);
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		error_quit(1);
	if (!(b->win = SDL_CreateWindow("RTv1",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
		b->winx, b->winy, SDL_WINDOW_SHOWN)))
		error_quit(1);
	b->img = SDL_GetWindowSurface(b->win);
}

/*
** Init for the viewplane struct
*/

void	init_vp(t_b *b)
{
            ft_putendlcolor("init_vp();", MAGENTA);
	b->vp.w = 0.5;
	b->vp.h = 0.35;
	b->vp.xi = b->vp.w / (double)b->winx;
	b->vp.yi = b->vp.h / (double)b->winy;
	b->vp.dist = 0;
		// printf("dist = %f\n", b->vp.dist);
	b->vp.upleft = vect_sub(vect_add(b->cam.dir, vect_add(vect_multnb(&b->cam.dir, b->vp.dist),
	vect_multnb(&b->cam.dirup, b->vp.h / 2))), vect_multnb(&b->cam.dirright, b->vp.w / 2));
}

/*
** Init the cam strcut values
*/

void	init_cam(t_cam *cam)
{
            ft_putendlcolor("init_cam();", MAGENTA);
	cam->angle = 60 * M_PI / 180;
	init_vect(&cam->pos, 0, 0, -3);
	init_vect(&cam->dir, 0, 0, 1);
	init_vect(&cam->dirup, 0, 1, 0);
	init_vect(&cam->dirright, 1, 0, 0);
	cam->dirright = vect_prod(cam->dir, cam->dirup);
		vect_print(cam->dirright);
}

/*
** Set the vector's values
*/

void	init_vect(t_v *vect, double x, double y, double z)
{
            ft_putendlcolor("init_vect();", MAGENTA);
	vect->x = x;
	vect->y = y;
	vect->z = z;
}

/*
** Init the lux struct
*/

void	init_lux(t_lux *lux, t_v pos)
{
	lux->pos = pos;
	lux->power = 1;
	lux->flux = 666;
}
