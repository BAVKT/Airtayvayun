/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 20:00:54 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/02 21:38:00 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Need creer un ft_atof()
** Need le parsing/check des faces
*/

/*
**	Basic draw
*/

void	draw(t_b *b)
{
            // ft_putendlcolor("draw();", MAGENTA);
	t_ray		ray;
	t_ray		to_light;
	t_lux		*lux;
	t_px		px;
	t_col		col;
	double		amp;
	int			i;
	int			j;

	px.x = 0;
	while (px.x < b->winx)
	{
		px.y = 0;
		while (px.y < b->winy)
		{
			ray.ori = b->cam.pos;
			ray.dir = vect_sub(draw_pixelvp(b, px), b->cam.pos);
			b->inter.id  = -1;
			inter_obj(b, &ray);
			if (ray.t < b->max)
			{
				vect_normalize(&b->inter.n);
				lux = b->lux;
				col = calc_amb(b);
				to_light.ori = ray2vect(ray);
				vect_normalize(&ray.dir);
				while (lux)
				{
					to_light.dir = vect_sub(lux->ori, to_light.ori);
					amp = 1 / (lux->amp_cst + lux->amp_lin * vect_norme(to_light.dir) + lux->amp_quad * vect_norme2(to_light.dir));
					inter_obj_lux(b, &to_light);
					lux->light = to_light.dir;
					vect_normalize(&lux->light);
					calc_dif(lux, b->inter);
					col = color_multnb(color_add(col, lux->lum_dif), amp);
					calc_spe(lux, b->inter, vect_multnb(&ray.dir, -1));
					col = color_multnb(color_add(col, lux->lum_spe), amp);
					lux = lux->next;
				}
				color_sat(&col);
			}
			else
				col = init_col(0.0, 0.0, 0.0);
			i = -1;
			while (++i < b->aliasing)
			{
				j = -1;
				while (++j < b->aliasing)
				{
					if (px.y + j < b->winy && px.x + i < b->winx)
					{
						SDL_LockSurface(b->img);
						if (i || j)
							*((unsigned int *)b->img->pixels + b->winx * (px.y + j) + px.x + i) = col2int(col);
						else
							*((unsigned int *)b->img->pixels + b->winx * (px.y + j) + px.x + i) = col2int(col);
						SDL_UnlockSurface(b->img);
						b->tab_px[px.y + j][px.x + i] = px;
						b->tab_px[px.y + j][px.x + i].col = col;
						b->tab_px[px.y + j][px.x + i].dist = 30 - ray.t;
						b->tab_px[px.y + j][px.x + i].id = b->inter.id;
					}
				}
			}
			px.y += b->aliasing;
		}
		px.x += b->aliasing;
	}
	// action(init_act());
	SDL_UpdateWindowSurface(b->win);
}

int main()
{
	t_b			b;

	init_b(&b);
	scene3(&b);
	while (event(&b))
		draw(&b);
	SDL_DestroyWindow(b.win);
	SDL_Quit();
	return 0;
}

void	loop()
{
}
