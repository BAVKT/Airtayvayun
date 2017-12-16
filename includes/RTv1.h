/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:44:32 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/16 21:09:57 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RTV1_H
# define __RTV1_H
# include "libft.h"
# include <SDL.h>
# include <math.h>
# include <limits.h>
					#include <stdio.h>
/*
** struct for a basic vector
*/

typedef struct				s_v
{
	double					x;
	double					y;
	double					z;
}							t_v;

/*
** Struct for the camera
*/

typedef struct				s_cam
{
	struct s_v				pos;
	struct s_v				dir;
	struct s_v				dirup;
	struct s_v				dirright;
	int						angle;
}							t_cam;

/*
** Spherical sphere struct
*/

typedef struct				s_sph
{
	t_v						center;
	double					r;
	unsigned int			color;
}							t_sph;

/*
** Ray struct
*/

typedef struct				s_ray
{
	t_v						ori;
	t_v						dir;
	double					t;
}							t_ray;

/*
**	Pixel struct
*/

typedef struct				s_px
{
	int						x;
	int						y;
	unsigned int 			color;
}							t_px;

/*
** Struct view plane - width/heigth/distance
*/

typedef	struct				s_vp
{
	double					w;
	double					h;
	double					xi;
	double					yi;
	double					dist;
	t_v						upleft;
}							t_vp;

/*
** The base struct, containing all we need to create life
*/

typedef struct				s_b
{
	int						winx;
	int						winy;
	struct s_cam			cam;
	struct s_vp				vp;
	struct s_sph			sph;
	SDL_Window				*win;
	SDL_Surface				*img;
}							t_b;


/*
** Structs inits						| init.c
*/

void						init_b(t_b *b);
void						init_vp(t_b *b);
void						init_cam(t_cam *cam);
void						init_vect(t_v *vect, double x, double y, double z);

/*
**	Errors								| error.c
*/

void						error();
void						error_quit(int e);

/*
**	Main & loop							| main.c
*/

int							main();
void						loop();
void						ray(t_b *b);

/*
**	Utilitaries							| Utils.c
*/

t_v							draw_pixelvp(t_b *b, t_px px);
t_v							ray2vect(t_ray ray);

/*
** Catch the events						| event.c
*/

int							event();
t_v							ev_move(t_v v, int ev);
void						ev_rotate_xy(t_b *b, int ev);

/*
**	Basic math between vectors			| vect_valc1.c
*/

t_v							vect_prod(t_v a, t_v b);
t_v							vect_add(t_v a, t_v b);
t_v							vect_sub(t_v a, t_v b);
double						vect_dot(t_v a, t_v b);

/*
**	Basic math with vector & nb			| vect_calc2.c
*/

t_v							vect_addnb(t_v *v, double nb);
t_v							vect_subnb(t_v *v, double nb);
t_v							vect_multnb(t_v *v, double nb);

/*
** Utilitaries about vectors			| vect_utils.c
*/

void						vect_normalize(t_v *v);
double						vect_norme(t_v v);
double						vect_norme2(t_v v);
void						vect_print(t_v v);
t_v							vect_rotate_xy(t_v v, double angle);
t_v							vect_init(double x, double y, double z);

/*
** Sphere								| sphere.c
*/

unsigned int				calc_sphere(t_ray ray, t_sph sph);


#endif