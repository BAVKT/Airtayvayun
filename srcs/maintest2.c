/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 20:00:54 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/16 20:07:39 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	draw(t_b *b)
{
            // ft_putendlcolor("draw();", MAGENTA);
	t_ray		ray;
	t_px		px;

	px.x = -1;
	px.color = rand() % INT_MAX;
	while (++px.x < b->winx)
	{
		px.y = -1;
		while (++px.y < b->winy)
		{
			ray.ori = b->cam.pos;
			ray.dir = vect_sub(draw_pixelvp(b, px), b->cam.pos);
			vect_normalize(&ray.dir);
			px.color = 0xff * (b->winx * px.y + px.x) / (b->winx * b->winy);
			// *((unsigned int *)b->img->pixels + b->winx * px.y + px.x) = px.color | px.color << 8 | px.color << 16;
				
			if (calc_sphere(ray, b->sph))
			{
				SDL_LockSurface(b->img);
				// printf("x = %d, y = %d\n", px.x, px.y);
				*((unsigned int *)b->img->pixels + b->winx * px.y + px.x) = calc_sphere(ray, b->sph) * 255;
				SDL_UnlockSurface(b->img);
			}
			else
				*((unsigned int *)b->img->pixels + b->winx * px.y + px.x) = 0;
		}
	}
	SDL_UpdateWindowSurface(b->win);
	ft_putendl("END");
}

int main()
{
	t_b			b;

	init_b(&b);
	b.sph.r = 0.1;
	b.sph.center = vect_init(0, 0, 10);
	while (event(&b))
		draw(&b);
	SDL_DestroyWindow(b.win);
	SDL_Quit();
	return 0;
}

void	loop()
{
}
