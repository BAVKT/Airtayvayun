/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:12:09 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/21 21:27:58 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Init the base struct
*/

void	init_b(t_b *b)
{
			ft_putendlcolor("init_b();", MAGENTA);
	int	i;

	b->p = 1.0;
	b->win = NULL;
	b->winx = 640 * 1.5;
	b->winy = 480 * 1.5;
	init_vp(b);
	init_cam(b);
	b->vl = NULL;
	b->lux = NULL;
	b->obj = NULL;
	b->amb = init_col(0.5, 0.5, 0.5);
	b->max = 66666666;
	b->aliasing = 4;
	b->colmax = 0.0;
	b->tab_px = (t_px**)malloc(sizeof(t_px*) * b->winy);
	i = -1;
	while (++i < b->winy)
		b->tab_px[i] = (t_px*)malloc(sizeof(t_px) * b->winx);
	//init_inter(b->inter);
}

/*
** SDL windows init
*/

void	init_win(t_b *b)
{
			ft_putendlcolor("init_win();", MAGENTA);
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		error_quit(1);
	if (!(b->win = SDL_CreateWindow("RTv1",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,
		b->winx, b->winy, SDL_WINDOW_SHOWN)))
		error_quit(1);
	b->img = SDL_GetWindowSurface(b->win);
}

/*
** VEry important function to INITIALIZE the inter min at 666666666
*/

void	init_inter(t_inter *inter)
{
	inter = (t_inter *)malloc(sizeof(t_inter));
	inter->min = 666666666;
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
** Vect list init
*/

t_vl		init_vl(t_v v, int id)
{
	t_vl	vl;

	vl.v = v;
	vl.id = id;
	return (vl);
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
	b->vp.dist = 15;
	b->vp.upleft = vect_add(b->cam.pos, vect_add(vect_multnb(&b->cam.dir, b->vp.dist),
		vect_multnb(&b->cam.dirup, b->vp.h / 2))), vect_multnb(&b->cam.dirright, -b->vp.w / 2);
}

/*
**	Init the color struct
*/

t_col	init_col(double r, double g, double b)
{
            // ft_putendlcolor("init_col();", MAGENTA);
	t_col	col;

	col.r = r;
	col.g = g;
	col.b = b;
	return (col);
}

/*
** Init for a matrice
*/

t_matrice	init_matrice()
{
	int			i;
	int			j;
	t_matrice	m;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			m.data[i][j] = 0;
	}
	return (m);
}

/*
** init texture struct
*/

t_tex		init_tex()
{
            // ft_putendlcolor("init_tex();", MAGENTA);
	t_tex	tex;

	tex.rug = 1.;
	tex.plasti = 0.;
	tex.refra = 0.;
	tex.trans = 0.;
	tex.hidden = 0;
	tex.reflect = 0.;
	tex.col = init_col(1.0, 1.0, 1.0);
	tex.ka = init_col(1.0, 1.0, 1.0);
	tex.kd = init_col(1.0, 1.0, 1.0);
	tex.ks = init_col(1.0, 1.0, 1.0);
	return (tex);
}

/*
** Init the action struct
** Action : 1 = Ellipse | 2 = axe	| 3 = color
** Axis   : 1 = X 		| 2 = Y 	| 3 = Z
*/

t_act		init_act(t_obj *obj1, int action, int axis)
{
            ft_putendlcolor("init_act();", MAGENTA);
	t_act act;

	act.action = action;
	act.obj1 = obj1;
	act.speed = 0.1;
	act.p = 0;			//Pour savoir si on deplace en positif ou en negatif
	act.next = NULL;
	act.min = -3;
	act.max = 3;
	if (axis == 1)
		act.axis = &obj1->ori.x;
	else if (axis == 2)
		act.axis = &obj1->ori.y;
	else if (axis == 3)
		act.axis = &obj1->ori.z;
	return (act);
}

/*
** Init the lux struct
*/

t_lux	init_lux(t_v pos, t_col dif, t_col spe)
{
            ft_putendlcolor("init_lux();", MAGENTA);
	t_lux	lux;

	lux.ori = pos;
	lux.dif = dif;
	lux.spe = spe;
	lux.amp_cst = 1.0;
			// sqrt(dif.r * dif.r + dif.g * dif.g + dif.b * dif.b);
			// + 0.5 / sqrt(spe.r * spe.r + spe.g * spe.g + spe.b * spe.b);
	lux.amp_lin = 0.001;
	lux.amp_quad = 0.0;
	lux.next = NULL;
	return (lux);
}

/*
**######################################################################
**								OBJETS
**######################################################################
*/

/*
** Init the cam strcut values
*/

void	init_cam(t_b *b)
{
		ft_putendlcolor("init_cam();", MAGENTA);
	b->cam.pos = init_vect(0, 0, -b->vp.dist);
	b->cam.dir = init_vect(0, 0, 1);
	refresh_dirright(&b->cam, init_vect(0, 1, 0));
}
/*
** Init for the plane
*/

t_obj	init_plane(double a, double b, double c, double d, t_col col)
{
            ft_putendlcolor("init_plane();", MAGENTA);
	t_obj plane;

	plane.form = 1;
	if (!a && !b && !c && !d)
		plane.b = 1.0;
	plane.a = a;
	plane.b = b;
	plane.c = c;
	plane.d = d;
	plane.r = 0;
	plane.h = init_vect(0.0, 0.0, 0.0);
	plane.ori = init_vect(0.0, 0.0, 0.0);
	plane.angle = 0;
	plane.tex = init_tex();
	plane.tex.ks = init_col(0.6, 0.6, 0.6);
	plane.tex.kd = init_col(0.7, 0.7, 0.7);
	plane.tex.col = (!col2int(col)) ? init_col(1.0, 1.0, 1.0) : col;
	plane.next = NULL;
	return (plane);
}

/*
** Init for sphere
*/

t_obj	init_sph(t_v v, t_col col, double r)
{
		ft_putendlcolor("init_sph();", MAGENTA);
	t_obj	sph;

	sph.form = 2;
	sph.a = 0;
	sph.b = 0;
	sph.c = 0;
	sph.d = 0;
	if (r < 0.01)
		r = 0.1;
	else
		sph.r = r;
	sph.ori = v;
	sph.angle = 0;
	sph.h = init_vect(0.0, 0.0, 0.0);
	sph.tex = init_tex();
	sph.tex.ks = init_col(0.7, 0.7, 0.7);
	sph.tex.kd = init_col(0.6, 0.6, 0.6);
	sph.tex.col = (!col2int(col)) ? init_col(1.0, 1.0, 1.0) : col;
	sph.next = NULL;
	return (sph);
}

/*
** Init for cone
*/

t_obj	init_cone(t_v v, t_col col, t_v h, double r)
{
            ft_putendlcolor("init_cone();", MAGENTA);
	t_obj	cone;

	cone.form = 4;
	cone.a = 0;
	cone.b = 0;
	cone.c = 0;
	cone.d = 0;
	if (r < 0.01)
		r = 0.1;
	else
		cone.r = r;
	cone.ori = v;
	cone.angle = DEG2RAD(20);
	cone.h = h;
	cone.tex = init_tex();
	cone.tex.ks = init_col(1.0, 1.0, 1.0);
	cone.tex.kd = init_col(1.0, 1.0, 1.0);
	cone.tex.col = (!col2int(col)) ? init_col(1.0, 1.0, 1.0) : col;
	cone.next = NULL;
	return (cone);
}

/*
** Init for cylindre
*/

t_obj		init_cyl(t_v v, t_col col, t_v h, double r)
{
            ft_putendlcolor("init_cyl();", MAGENTA);
	t_obj cyl;

	cyl.form = 3;
	cyl.a = 0;
	cyl.b = 0;
	cyl.c = 0;
	cyl.d = 0;
	if (r < 0.01)
		r = 0.1;
	else
		cyl.r = r;
	cyl.h = h;
	cyl.ori = v;
	cyl.angle = 0;
	cyl.tex = init_tex();
	cyl.tex.ks = init_col(1.0, 1.0, 1.0);
	cyl.tex.kd = init_col(1.0, 1.0, 1.0);
	cyl.tex.col = (!col2int(col)) ? init_col(1.0, 1.0, 1.0) : col;
	cyl.next = NULL;
	return (cyl);
}

/*
** Init plane V2.0 the return of the comeback
*/

t_obj		init_plane2(t_v ori, t_v h, t_v w)
{
	t_v		n;
	t_obj	p;
	// double	nb;

	n = vect_prod(w, h);
	vect_normalize(&n);
	p = init_plane(n.x, n.y, n.z, -vect_dot(n, ori), init_col(1.0, 1.0, 1.0));
	return (p);
}

/*
** Init ray
*/

t_ray	init_ray(t_v ori, t_v dir, double t)
{
		// ft_putendlcolor("init_ray();", MAGENTA);
	t_ray	ray;

	ray.ori = ori;
	ray.dir = dir;
	ray.t = t;
	return (ray);
}




























