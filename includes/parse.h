/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 15:08:55 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/13 16:37:53 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARSE_H
# define __PARSE_H
# include "RTv1.h"

/*
	Virer la structure sommet et face

*/


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
	unsigned int			som1;
	unsigned int			som2;
	unsigned int			som3;
}							t_face;

/*
** Parsing struct
*/

typedef struct				s_pars
{
	t_v						*v;				//Sommet
	t_v						*vt;			//Coordonnée de texture
	t_v						*vn;			//Normale sommet
	t_face					*face;			//Face
}							t_pars;

/*
** to stock the MTL files values
*/

typedef struct				s_mtl
{
	t_col					Ka;			//couleur ambiante (la couleur de l'objet sans lumière directe)
	t_col					Kd;			//couleur diffuse (la couleur de l'objet sous lumière blanche)
	t_col					Ks;			//couleur spéculaire
	t_col					Ke;			//couleur émissive
	double					Ni;			//densité optique
	double					Ns;			//specular exponent entre 0 et 100
	double					d;			//transparence entre 0 et 1 (aucune transparence)
	double					illum;		//paramètres de lumières
	// double				map_kd;		//(ks, ka) pour la texture utilisé diffuse (specular, ambiante)
	struct s_mtl			*next;
}							t_mtl;

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

#endif