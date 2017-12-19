/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 20:00:54 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/19 20:44:37 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	draw(t_b *b)
{
            // ft_putendlcolor("draw();", MAGENTA);
	t_ray		ray;
	t_px		px;
	double		min;
	int			id;
	int			crossid;

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
				crossid = id;
			else if ((id = inter_plane(&b->plane, ray, &min)) > 0)
				crossid = id;
			if (crossid > 0)
			{
				SDL_LockSurface(b->img);

				*((unsigned int *)b->img->pixels + b->winx * px.y + px.x) = 0xffffff;
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
	init_sph(&b.sph, init_vect(0, 0, 10), init_col(1, 1, 1));
	while (event(&b))
		draw(&b);
	SDL_DestroyWindow(b.win);
	SDL_Quit();
	return 0;
}

void	loop()
{
}
