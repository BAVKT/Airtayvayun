/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:12:09 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/19 22:22:15 by vmercadi         ###   ########.fr       */
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
** Vect init
*/

t_v		init_vect(double x, double y, double z)
{
	t_v	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
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
	cam->pos = init_vect(0, 0, -3);
	cam->dir = init_vect(0, 0, 1);
	cam->dirup =init_vect(0, 1, 0);
	cam->dirright = init_vect(1, 0, 0);
	cam->dirright = vect_prod(cam->dir, cam->dirup);
}

/*
** Init for sphere
*/

t_sph	init_sph(t_v v, t_col col)
{
            ft_putendlcolor("init_sph();", MAGENTA);
	t_sph	sph;

	sph.r = 0.5;
	sph.center = v;
	sph.color = col;
	sph.next = NULL;
	return (sph);
}

/*
** Init the lux struct
*/

t_lux	init_lux(t_v pos)
{
            ft_putendlcolor("init_lux();", MAGENTA);
	t_lux	lux;

	lux.ori = pos;
	lux.amb = init_col(1.0, 1.0, 1.0);
	lux.dif = init_col(0.0, 0.0, 0.0);
	lux.spe = init_col(0.0, 0.0, 0.0);
	lux.col = init_col(1.0, 1.0, 1.0);
	lux.next = NULL;
	return (lux);
}

/*
** Init ofr the plane
*/

t_plane		init_plane(double a, double b, double c, double d)
{
	t_plane plane;

	plane.a = a;
	plane.b = b;
	plane.c = c;
	plane.d = d;
	plane.next = NULL;
	return (plane);
}

/*
**	Init the color struct
*/

t_col	init_col(double r, double g, double b)
{
	t_col	col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

/*
** init texture struct
*/

t_tex		init_tex()
{
	t_tex	tex;

	tex.rug = 1;
	tex.plasti = 0;
	tex.refra = 0;
	tex.trans = 0;
	tex.hidden = 0;
	tex.reflect = 0;
	tex.col = init_col(0.0, 1.0, 0.1);
	tex.ka = init_col(1.0, 1.0, 1.0);
	tex.kd = init_col(0.0, 0.0, 0.0);
	tex.ks = init_col(0.0, 0.0, 0.0);
	return (tex);
}







