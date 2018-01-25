/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 20:00:54 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/19 18:06:30 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Need creer un ft_atof()
** Need le parsing/check des faces
**
** Creation de la struct s_som
** Creation de la struct s_face
** Creation de la struct s_vl
** Ajout de init_vectl()
** Ajout de parse_error()
** Ajout de parse_main()
** Ajout de parse_redirect()
** Ajout de parse_som()
** Ajout de ft_implode()
*/

// void	shadow(t_b *b, t_ray light, t_lux *lux)
// {

// }

/*
**	Basic draw
*/

void	draw(t_b *b)
{
            ft_putendlcolor("draw();", MAGENTA);
	t_ray		ray;
	t_ray		light;
	t_lux		*lux;
	t_px		px;
	t_col		col;

	px.x = -1;
	while (++px.x < b->winx)
	{
		px.y = -1;
		while (++px.y < b->winy)
		{
			ray.ori = b->cam.pos;
			ray.dir = vect_sub(draw_pixelvp(b, px), b->cam.pos);
			if ((b->inter = inter_obj(b, &ray)))
			{
				vect_normalize(&b->inter->n);
				lux = b->lux;
				vect_normalize(&ray.dir);
				col = calc_amb(b);
				while (lux)
				{
					if ((b->inter = inter_obj(b, &ray)))
					{
						lux->light = vect_sub(lux->ori, ray2vect(ray));
						vect_normalize(&lux->light);
						light.ori = vect_multnb(&ray.dir, ray.t);
						light.dir = lux->light;
						calc_dif(lux, *b->inter);
						// calc_spe(lux, *b->inter, vect_multnb(&ray.dir, -1));
						col = color_add(col, lux->lum_dif);
					}
					// if (px.y == 0)
					// 	print_col(col);
					lux = lux->next;
				}
				color_sat(&col);
				SDL_LockSurface(b->img);
				*((unsigned int *)b->img->pixels + b->winx * px.y + px.x) = col2int(col);
				SDL_UnlockSurface(b->img);
			}
			else
				*((unsigned int *)b->img->pixels + b->winx * px.y + px.x) = 0;
		}
	}
	SDL_UpdateWindowSurface(b->win);
}

int main()
{
	t_b			b;

	init_b(&b);
	add_lux(&b, init_lux(init_vect(10.0, 0.0, 0.0)));
	add_sphere(&b, init_sph(init_vect(0, 0, 10), init_col(0.0, 1.0, 0.0)));
	add_plane(&b, init_plane(0.0, 1.0, 0.0, 3.0));
	b.sph->tex.col = init_col(1.0, 1.0, 1.0);
	b.plane->tex.col = init_col(0.0, 1.0, 1.0);
	while (event(&b))
		draw(&b);
	SDL_DestroyWindow(b.win);
	SDL_Quit();
	return 0;
}

void	loop()
{
}
