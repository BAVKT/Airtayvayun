/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:56:35 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/17 18:36:58 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** To check the diferents help
*/

void	man_help()
{
	ft_putendlcolor("./RTv1 usage			//How to use RTv1", YELLOW);
	ft_putendlcolor("./RTv1 help input		//Exemple of a correct scene file", YELLOW);
	ft_putendlcolor("./RTv1 help obj		//Exemple of a correct .obj file", YELLOW);
	exit (1);
}

/*
** Help for file format
*/

void	help_parsing()
{
	ft_putendl("Lumière ambiante :       densité");
	ft_putendl("EX : amb             0.4/0.4/0.4\n");
	ft_putendl("Plane :     a   b   c   d      color");
	ft_putendl("EX: plane  0.0 1.0 0.0 3.0  1.0/0.0/1.0\n");
	ft_putendl("Sphere :    Position       color     rayon");
	ft_putendl("EX: sph    3.0/0.0/5.0  1.0/0.0/1.0  1.0\n");
	ft_putendl("Cylindre :  Position       color          h       rayon");
	ft_putendl("EX : cyl   2.0/2.0/3.0  0.0/0.0/1.0  1.0/0.0/0.0  1.0\n");
	ft_putendl("Cone :      Position       color          h       rayon");
	ft_putendl("EX : cone  0.0/0.0/5.0  1.0/1.0/1.0  1.0/0.0/0.0  1.0\n");
	ft_putendl("Lumiere :   Position       Diffuse    Spéculaire");
	ft_putendl("EX : lux   0.0/0.0/5.0  0.0/0.2/0.2  0.0/0.5/0.5\n");
	ft_putendl("----------------------------------------------------------\n");
	ft_putendl("File exemple :\n");
	ft_putendl("amb      0.4/0.4/0.4");
	ft_putendl("plane    0.0/1.0/0.0/3.0  1.0/0.0/1.0");
	ft_putendl("sph      3.0/0.0/5.0      1.0/0.0/1.0     0.2");
	ft_putendl("sph      0.0/2.0/5.0      1.0/0.0/1.0     1.0");
	ft_putendl("sph      5.0/2.0/5.0      1.0/0.0/1.0     3.0");
	ft_putendl("cyl      2.0/2.0/3.0      0.0/0.0/1.0     1.0/0.0/0.0     1.0");
	ft_putendl("cone     0.0/0.0/5.0      1.0/1.0/1.0     1.0/0.0/0.0     1.0");
	ft_putendl("lux      0.0/0.0/5.0      0.0/0.2/0.2     0.0/0.5/0.5");
	ft_putendl("lux      2.0/3.0/5.0      0.7/0.7/0.7     0.7/0.7/0.7");
	exit (1);
}

/*
** Help .obj format
*/

void	help_obj()
{
	ft_putendl("File exemple : \n");
	ft_putendl("# Blender3D v249 OBJ                //Comment");
	ft_putendl("mtllib cube.mtl                     //New material");
	ft_putendl("v 1.000000 -1.000000 -1.000000		//Vertex (sommet)");
	ft_putendl("v 1.000000 -1.000000 1.000000");
	ft_putendl("v -1.000000 -1.000000 1.000000");
	ft_putendl("v -1.000000 -1.000000 -1.000000");
	ft_putendl("vt 0.748573 0.750412                //Texture coord");
	ft_putendl("vt 0.749279 0.501284");
	ft_putendl("vt 0.999110 0.501077");
	ft_putendl("vt 0.999455 0.750380");
	ft_putendl("vt 0.250471 0.500702");
	ft_putendl("vt 0.249682 0.749677");
	ft_putendl("vn 0.000000 0.000000 -1.000000      //Vertex normale");
	ft_putendl("vn -1.000000 -0.000000 -0.000000");
	ft_putendl("vn -0.000000 -0.000000 1.000000");
	ft_putendl("vn -0.000001 0.000000 1.000000");
	ft_putendl("usemtl Material_ray.png");
	ft_putendl("f 3/1/1 1/2/1 4/3/1                 //Vertex of a face");
	ft_putendl("f 2/1/1 4/3/1 1/4/1");
	ft_putendl("f 3/4/2 3/2/2 3/4/2");
	exit (1);
}

void	usage()
{
	ft_putendlcolor("./RTv1", GREEN);
	ft_putendlcolor("     OR", GREEN);
	ft_putendlcolor("./RTv1 scene_file", GREEN);
	ft_putendlcolor("     OR", GREEN);
	ft_putendlcolor("./RTv1 file.obj         //Execute ", GREEN);
	ft_putendlcolor("     OR", GREEN);
	ft_putendlcolor("./RTv1 help             //For more infos", GREEN);
	exit (1);
}