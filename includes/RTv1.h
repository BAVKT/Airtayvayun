/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RTv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 18:44:32 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/12 15:22:04 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __RTV1_H
# define __RTV1_H
# include "libft.h"
// # include "parse.h"
# include <SDL.h>
// # include <SDL_image.h>
// # include <SDL_ttf.h>
# include <math.h>
# include <limits.h>
# define MAX_DEEP 1
# define DEG2RAD(x) (x * M_PI / 180.0)
					#include <stdio.h>


//Specular entre le rayon envoyé et le rayon de la lumiere et on blanchi le pixel

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
	t_v						v;
	int						id;
	struct s_vl				*next;
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
	int						id;
	int						x;
	int						y;
	t_col		 			col;
	double					dist;
}							t_px;

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
** Light struct
*/

typedef	struct				s_lux
{
	double					atn;		//Attenuation
	double					amp_cst;	//Amplitude constante
	double					amp_lin;	//Amplitude lineaire
	double					amp_quad;	//Amplitude quadratique
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
** Struct for the camera
*/

typedef struct				s_cam
{
	t_v						pos;
	t_v						dir;
	t_v						dirup;
	t_v						dirright;
	int						id;
	struct s_cam			*next;
}							t_cam;

/*
** Obj struct containing every kind of object
*/

typedef	struct				s_obj
{
	int						form;	//1 = plan, 2 = sph, 3 = cyl, 4 = cone
	int						id;
	double					a;
	double					b;
	double					c;
	double					d;
	double					r;
	double					angle;
	t_v						h;
	t_v						ori;
	t_tex					tex;
	struct s_obj			*next;
}							t_obj;

/*
** Intersection struct
*/

typedef struct				s_inter
{
	t_ray					to_cam;
	t_ray					to_lux;
	t_tex					tex;
	t_v						n;
	int						id;
	double					min;
}							t_inter;

/*
** Action struct
*/

typedef struct				s_act
{
	int						action;		//1 = ellipse, 2 = move axe
	int						p;			//TO know if we need to increase or decrease
	double					speed;		//vitesse de l'action
	double					dist;
	double					max;		//Dist max
	double					min;		//dist min
	double					angle;
	double					*axis;		//pointeur sur l'axe correspondant
	double					start;
	t_obj					*obj1;
	t_obj					*obj2;
	struct s_act			*next;
}							t_act;

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
	double					colmax;	//max color
	int						id;		//Id de l'objet selectionné
	int						p;		//Pour les actions pour savoir si on deplace. Oui faut trouver comment faire autrement parceque c'est deguelasse
	int						winx;
	int						winy;
	int						maxid;
	int						aliasing;
	t_act					*act;
	t_px					**tab_px;
	t_vl					*vl;			//Liste du centre des objets
	// t_pars					pars;
	t_cam					cam;
	t_vp					vp;
	t_obj					*obj;
	t_lux					*lux;
	t_col					amb;		//intensité ambiante
	t_inter					inter;
	SDL_Window				*win;
	SDL_Surface				*img;
}							t_b;

/*
** main functions						| maintest2.c
*/

void						rt(t_b *b);
void						draw(t_b *b);
void						draw_lux(t_b *b);


/*
** Structs inits						| init.c
*/

void						init_b(t_b *b);
void						init_vp(t_b *b);
void						init_cam(t_cam *cam);
t_v							init_vect(double x, double y, double z);
t_vl						init_vl(t_v v, int id);
t_lux						init_lux(t_v pos);
t_obj						init_sph(t_v v, t_col color);
t_col						init_col(double r, double g, double b);
t_obj						init_plane(double a, double b, double c, double d, t_col col);
t_tex						init_tex();
void						init_inter(t_inter *inter);
t_matrice					init_matrice();
t_obj						init_cone(t_v v, t_col col, t_v h);
t_obj						init_cyl(t_v v, t_col col, t_v h, double r);
t_act						init_act(t_obj *obj1, int action, int axis);

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
double						solve_equation(double min, double a, double b, double c);
t_px						pos2px(t_b *b, t_v v);

/*
** Catch the events						| event.c
*/

int							event();
void						ev_move_cam(t_b *b, int ev);
void						ev_rotate_xy(t_b *b, int ev);
void						ev_qualitat(t_b *b, int ev);
void						ev_reset(t_b *b);

/*
** Event on objects
*/

void						event_obj(t_b *b, int ev);
void						ev_move_obj(t_b *b, int ev);
void						ev_move_lum(t_b *b, int ev);
void						ev_mouse(t_b *b);

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
** Vector list actions					| vector.c
*/

t_vl						*add_vl(t_b *b, t_vl vl);
t_vl						*search_vl(t_b *b, int id);

/*
** Utilitaries for color				| color.c
*/

t_col						get_color(t_b *b, t_ray ray);
t_col						color_add(t_col col, t_col col2);
t_col						color_mult(t_col col, t_col col2);
t_col						color_multnb(t_col col, double nb);
void						color_sat(t_col *col);
unsigned int				col2int(t_col col);
void						print_col(t_col col);
void						color_max(t_col col, double *colmax);

/*
** Intercept for objs 					| intersection.c
*/

double						inter_obj(t_b *b, t_ray *ray);
double						inter_obj_lux(t_b *b, t_ray *ray);
int							inter_all(t_b *b, t_ray *ray, double min);

/*
** Calculation for the differents obj	| calc_obj.c
*/

double						calc_sphere(t_ray *ray, t_obj sph, double min);
double						calc_plane(t_ray *ray, t_obj plane, double min);
double						calc_cone(t_ray *ray, t_obj cone, double min);
double						calc_cyl(t_ray *ray, t_obj cyl, double min);

/*
** Interact with obj list				| obj.c
*/

t_obj						*add_obj(t_b *b, t_obj obj);
t_obj						*search_obj(t_b *b, int id);
void						delete_obj(t_b *b, int id);

/*
** Lux									| lux.c
*/

t_col						calc_amb(t_b *b);
void						calc_dif(t_lux *lux, t_inter inter);
void						calc_spe(t_lux *lux, t_inter inter, t_v to_eye);
t_lux						*add_lux(t_b *b, t_lux lux);
t_lux						*search_lux(t_b *b, int id);

/*
** The differents scenes
*/

void						scene1(t_b *b);
void						scene2(t_b *b);
void						scene3(t_b *b);
void						scene4(t_b *b);
void						scene5(t_b *b);
void						scene6(t_b *b);

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

/*
** Actions to animate scene				| action.c
*/

void						action(t_act *act);
t_act						*add_action(t_b *b, t_act act);
void						set_act(t_act *act, double min, double max, int axis);
void						act_movaxis(t_act *act);
void						act_ellipse(t_act *act);
void						act_color(t_obj *obj);


/*
** To create a FDF map of the actual scene
*/

void						to_fdf(t_b *b, char *name);





















#endif