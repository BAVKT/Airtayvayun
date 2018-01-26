/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:22:46 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/26 16:24:51 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	scene1(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, 0.0)));
	add_sphere(b, init_sph(init_vect(0, 0, 10), init_col(1.0, 1.0, 1.0)));
	add_plane(b, init_plane(0.0, 1.0, 0.0, 3.0, init_col(1.0, 0.0, 0.0)));
}

void	scene2(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, 25.0)));
	add_sphere(b, init_sph(init_vect(0, 0, 10), init_col(1.0, 1.0, 0.0)));
	add_sphere(b, init_sph(init_vect(2, 2, 10), init_col(0.0, 0.0, 1.0)));
	add_sphere(b, init_sph(init_vect(0, 2, 10), init_col(0.0, 1.0, 0.0)));
	add_sphere(b, init_sph(init_vect(2, 0, 10), init_col(1.0, 0.0, 0.0)));

	add_sphere(b, init_sph(init_vect(0, 4, 10), init_col(1.0, 1.0, 1.0)));
	add_sphere(b, init_sph(init_vect(0, 6, 10), init_col(1.0, 1.0, 1.0)));
	add_sphere(b, init_sph(init_vect(0, 8, 10), init_col(1.0, 1.0, 1.0)));
	add_sphere(b, init_sph(init_vect(0, 10, 10), init_col(1.0, 1.0, 1.0)));
	add_sphere(b, init_sph(init_vect(4, 0, 10), init_col(1.0, 1.0, 1.0)));
	add_sphere(b, init_sph(init_vect(6, 0, 10), init_col(1.0, 1.0, 1.0)));
	add_sphere(b, init_sph(init_vect(8, 0, 10), init_col(1.0, 1.0, 1.0)));
	add_sphere(b, init_sph(init_vect(10, 0, 10), init_col(1.0, 1.0, 1.0)));

	//Mur du fond
	add_plane(b, init_plane(0.0, 0.0, 1.0, -15.0, init_col(0.4, 0.0, 0.0)));
	//Mur de droite
	add_plane(b, init_plane(1.0, 0.0, 0.0, 15.0, init_col(0.4, 0.0, 0.0)));
	//Mur droit
	add_plane(b, init_plane(1.0, 0.0, 0.0, -15.0, init_col(0.4, 0.0, 0.0)));
	//Mur gauche jaune
	add_plane(b, init_plane(0.0, 1.0, 0.0, 15.0, init_col(0.4, 0.0, 0.0)));
	//sol violet
	add_plane(b, init_plane(0.0, 1.0, 0.0, 15.0, init_col(0.4, 0.0, 0.0)));
}

void	scene3(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, 25.0)));
	add_sphere(b, init_sph(init_vect(0, 0, 10), init_col(1.0, 1.0, 1.0)));
	add_sphere(b, init_sph(init_vect(2, 2, 10), init_col(0.0, 0.0, 1.0)));
	add_sphere(b, init_sph(init_vect(0, 2, 10), init_col(1.0, 1.0, 0.0)));
	add_sphere(b, init_sph(init_vect(2, 0, 10), init_col(1.0, 0.0, 0.0)));
	add_plane(b, init_plane(0.0, 1.0, 0.0, 3.0, init_col(1.0, 0.0, 0.0)));
}

void	scene4(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, 25.0)));
	add_sphere(b, init_sph(init_vect(0, 0, 10), init_col(1.0, 1.0, 1.0)));
	add_plane(b, init_plane(0.0, 1.0, 0.0, 3.0, init_col(1.0, 0.0, 0.0)));
}

void	scene5(t_b *b)
{
	add_lux(b, init_lux(init_vect(0.0, 0.0, 25.0)));
	add_sphere(b, init_sph(init_vect(0, 0, 10), init_col(1.0, 1.0, 1.0)));
	add_plane(b, init_plane(0.0, 1.0, 0.0, 3.0, init_col(1.0, 0.0, 0.0)));
}
