/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 20:00:54 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/04 21:12:30 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	draw(t_b *b)
{
            ft_putendlcolor("draw();", MAGENTA);
	t_ray		ray;
	t_sph		*sph;
	t_lux		*lux;
	t_plane		*plane;
	t_tex		tex;
	t_px		px;
	t_v			n;
	t_col		col;
	double		min;
	int			id;
	int			crossid;
	int			sphere;

	px.x = -1;
	while (++px.x < b->winx)
	{
		px.y = -1;
		while (++px.y < b->winy)
		{
			min = 666666666;
			crossid = -1;
			ray.ori = b->cam.pos;
			ray.dir = vect_sub(draw_pixelvp(b, px), b->cam.pos);
			vect_normalize(&ray.dir);
			if ((id = inter_sphere(&b->sph, ray, &min)) > 0)
			{
				sph = search_sphere(b, id);
				sph->tex.col = init_col(1.0, 1.0, 0.0);
				tex = sph->tex;
				ray.t = min;
				n = vect_sub(sph->center, ray2vect(ray));
				sphere = 1;
				crossid = id;
						// printf("yolo1\n");
			}
			else if ((id = inter_plane(&b->plane, ray, &min)) > 0)
			{
				plane = search_plane(b, id);
				plane->tex.col = init_col(0.0, 0.0, 1.0);
				tex = plane->tex;
				ray.t = min;
				n = init_vect(plane->a, plane->b, plane->c);
				sphere = 0;
				crossid = id;
						// printf("yolo2\n");
			}
			if (crossid > 0)
			{
				vect_normalize(&n);
				lux = b->lux;
						// printf("yolo3\n");
				while (lux)
				{
					calc_amb(lux, tex);
					lux->light = vect_sub(lux->ori, ray2vect(ray));
					vect_normalize(&lux->light);
					calc_dif(lux, tex, n);
					col = color_add(lux->lum_amb, lux->lum_dif);
					lux = lux->next;
				}
				SDL_LockSurface(b->img);
				*((unsigned int *)b->img->pixels + b->winx * px.y + px.x) = col2int(col);
				SDL_UnlockSurface(b->img);
						// printf("yolo4\n");
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
	add_lux(&b, init_lux(init_vect(0.0, 0.0, 25.0)));
	add_sphere(&b, init_sph(init_vect(0, 0, 10), init_col(1.0, 1.0, 1.0)));
	add_plane(&b, init_plane(0.0, 1.0, 0.0, 3.0));
	while (event(&b))
		draw(&b);
	SDL_DestroyWindow(b.win);
	SDL_Quit();
	return 0;
}

void	loop()
{
}
