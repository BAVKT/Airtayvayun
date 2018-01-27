/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:44:32 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/26 21:55:22 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RTV1_H
# define __RTV1_H
# include "libft.h"
# include <SDL.h>
# include <math.h>
# include <limits.h>
# define MAX_DEEP 1
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
** struct for a basic list of vectors
*/

typedef struct				s_vl
{
	double					x;
	double					y;
	double					z;
	struct s_v				*next;
}							t_vl;

/*
** Color struct
*/

typedef struct				s_col
{
	double					r;
	double					g;
	double					b;
}							t_col;

/*
** Texture struct
*/

typedef struct				s_tex
{
	double					plasti;		//plasticité
	double					refra;		//indice de refraction
	double					trans;		//indice de transparence
	double					reflect;	//reflectivite
	double					rug;		//rugosité
	int						hidden;
	//t_v						n;			//normale oklm trkl
	t_col					col;		//color
	t_col					ka;			//coef lum ambiant
	t_col					kd;			//coef lum diffuse
	t_col					ks;			//coef lum specular
}							t_tex;

/*
** Struct for the camera
*/

typedef struct				s_cam
{
	int						angle;
	t_v						pos;
	t_v						dir;
	t_v						dirup;
	t_v						dirright;
	int						id;
	struct s_cam			*next;
}							t_cam;

/*
** Spherical sphere struct
*/

typedef struct				s_sph
{
	double					r;
	t_v						center;
	t_col					color;
	t_tex					tex;
	int						id;
	struct s_sph			*next;
}							t_sph;

/*
** Ray struct
*/

typedef struct				s_ray
{
	double					t;
	t_v						ori;
	t_v						dir;
}							t_ray;

/*
**	Pixel struct
*/

typedef struct				s_px
{
	int						x;
	int						y;
	t_col		 			color;
}							t_px;

/*
** Light struct
*/

typedef	struct				s_lux
{
	double					atn;		//Attenuation
	t_v						ori;		//origine
	t_v						light;		//vecteur vers la lumiere
	t_col					dif;		//intensite de la lumiere diffuse
	t_col					spe;		//intensite lumiere speculaire
	t_col 					lum_amb;	//luminosite ambiante
	t_col					lum_dif;	//luminosite de la lumiere diffuse
	t_col					lum_spe;	//luminosite lum speculaire
	t_col					col;		//Couleur
	int						id;
	struct s_lux			*next;
}							t_lux;

/*
** Struct view plane | width/heigth/distance
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
** Plane struct	| Contain the abcd for the plane equation
*/

typedef struct				s_plane
{
	double					a;
	double					b;
	double					c;
	double					d;
	int						id;
	t_tex					tex;
	struct s_plane			*next;
}							t_plane;

/*
** Sommet d'une face
*/

typedef struct				s_som
{
	t_v						v;		//Sommet
	t_v						vt;		//Coordonnée texture pour un sommet
	t_v						vn;		//Normale du sommet
}							t_som;

/*
** List of the faces of the obj
*/

typedef struct				s_face
{
	unsigned int			id;
	t_som					som1;
	t_som					som2;
	t_som					som3;
	struct s_face			*next;
}							t_face;

/*
** Parsing struct
*/

typedef struct				s_pars
{
	t_vl					*v;
	t_vl					*vt;
	t_vl					*vn;
	t_face					*facelist;
}							t_pars;

/*
** Intersection struct
*/

typedef struct				s_inter
{
	t_ray					to_cam;
	t_ray					to_lux;
	t_tex					tex;
	t_v						n;
	double					min;
}							t_inter;

/*
** Struct for a 3x3 matrice
*/

typedef struct				s_matrice
{
	double					data[3][3];
}							t_matrice;

/*
** The base struct, containing all we need to create life
*/

typedef struct				s_b
{
	double					max;
	int						winx;
	int						winy;
	int						maxid;
	int						aliasing;
	t_pars					pars;
	t_cam					cam;
	t_vp					vp;
	t_sph					*sph;
	t_plane					*plane;
	t_lux					*lux;
	t_col					amb;		//intensité ambiante
	t_inter					*inter;
	SDL_Window				*win;
	SDL_Surface				*img;
}							t_b;

/*
** Structs inits						| init.c
*/

void						init_b(t_b *b);
void						init_vp(t_b *b);
void						init_cam(t_cam *cam);
t_v							init_vect(double x, double y, double z);
t_vl						init_vectl(double x, double y, double z);
t_lux						init_lux(t_v pos);
t_sph						init_sph(t_v v, t_col color);
t_col						init_col(double r, double g, double b);
t_plane						init_plane(double a, double b, double c, double d, t_col col);
t_tex						init_tex();
void						init_inter(t_inter *inter);
t_matrice					init_matrice();

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
t_v							ev_move(t_b *b, int ev);
void						ev_rotate_xy(t_b *b, int ev);
void						ev_qualitat(t_b *b, int ev);
void						ev_reset(t_b *b);


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

double						vect_norme(t_v v);
double						vect_norme2(t_v v);
void						vect_print(t_v v);
void						vect_normalize(t_v *v);
t_v							vect_rotate(t_v v, double angle, t_v axe);
t_v							vect_init(double x, double y, double z);

/*
** Utilitaries for color				| color.c
*/

t_col						color_add(t_col col, t_col col2);
t_col						color_mult(t_col col, t_col col2);
t_col						color_multnb(t_col col, double nb);
void						color_sat(t_col *col);
unsigned int				col2int(t_col col);
void						print_col(t_col col);


/*
** Intercept for objs 					| intersection.c
*/

int							inter_sphere(t_b *b, t_ray *ray);
int							inter_plane(t_b *b, t_ray *ray);
t_inter						*inter_obj(t_b *b, t_ray *ray);

/*
** Sphere								| sphere.c
*/

double						calc_sphere(t_ray *ray, t_sph sph);
t_sph						*add_sphere(t_b *b, t_sph sph);
t_sph						*search_sphere(t_b *b, int id);

/*
**	Plane								| plane.c
*/

double						calc_plane(t_ray *ray, t_plane plane);
t_plane						*add_plane(t_b *b, t_plane plane);
t_plane						*search_plane(t_b *b, int id);

/*
** Lux									| lux.c
*/

t_col						calc_amb(t_b *b);
void						calc_dif(t_lux *lux, t_inter inter);
void						calc_spe(t_lux *lux, t_inter inter, t_v eye);
t_lux						*add_lux(t_b *b, t_lux lux);
t_lux						*search_lux(t_b *b, int id);

/*
** Obj parsing							| parseur.c
*/
void						parse_error(int e, char *s);
void						parse_main(t_b *b, char *av);
void						parse_redirect(t_pars *pars, char *s);
void						parse_v(t_pars *pars, char **tab);
void						parse_vt(t_pars *pars, char **tab);
void						parse_vn(t_pars *pars, char **tab);
void						parse_f(t_pars *pars, char **tab);
void						check_f(char **tab);
void						parse_mtl(char *s);
int							ft_isnum(char *str);
char						*ft_implode(char **tab, char c);

/*
** The differents scenes
*/

void						scene1(t_b *b);
void						scene2(t_b *b);
void						scene3(t_b *b);
void						scene4(t_b *b);
void						scene5(t_b *b);

/*
** Matrice calculations functions
*/

t_matrice					matrice_add(t_matrice a, t_matrice b);
t_matrice					matrice_sub(t_matrice a, t_matrice b);
t_matrice					matrice_mult(t_matrice a, t_matrice b);
t_matrice					matrice_multnb(t_matrice a, double nb);
t_v							matrice_multvect(t_matrice m, t_v v);

/*
** Cam refreshing
*/

void						refresh_dir(t_cam *cam, t_v v);
void						refresh_dirup(t_cam *cam, t_v v);
void						refresh_dirright(t_cam *cam, t_v v);















#endif