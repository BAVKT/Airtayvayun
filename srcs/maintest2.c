/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maintest2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 20:00:54 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/20 09:51:11 by vmercadi         ###   ########.fr       */
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

void	rt(t_b *b)
{
            // ft_putendlcolor("draw();", MAGENTA);
	t_px		px;
	t_ray		ray;
	t_col		col;
	int			i;
	int			j;

	px.x = 0;
	while (px.x < b->winx)
	{
		px.y = 0;
		while (px.y < b->winy)
		{
			ray = init_ray(b->cam.pos, vect_sub(draw_pixelvp(b, px), b->cam.pos), 1.0);
			// b->inter.tex = init_tex();
			// b->inter.n = b->cam.dir;
			// col = get_color(b, ray);
			b->inter.id  = -1;
			// if (vect_dot(ray.dir, b->cam.dir) > 0)
				ray.t = b->max;	
				inter_obj(b, &ray);
			col = get_color(b, ray);
			// col = color_add(col, get_color(b, ray));
			i = -1;
			while (++i < b->aliasing)
			{
				j = -1;
				while (++j < b->aliasing)
				{
					if (px.y + j < b->winy && px.x + i < b->winx)
					{
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
	draw_lux(b);
	draw(b);
	action(b->act);
	SDL_UpdateWindowSurface(b->win);
}

void		draw(t_b *b)
{
	t_px		px;
	int			i;
	int			j;
	t_col		col;

		// printf("colmax = %f\n", b->colmax);
		// printf("colmax = %d\n", RAND_MAX);
	px.x = 0;
	while (px.x < b->winx)
	{
		px.y = 0;
		while (px.y < b->winy)
		{
			i = -1;
			while (++i < b->aliasing)
			{
				j = -1;
				while (++j < b->aliasing)
				{
					if (px.y + j < b->winy && px.x + i < b->winx)
					{
						col = color_multnb(b->tab_px[px.y + j][px.x + i].col, 1 / b->colmax);
						SDL_LockSurface(b->img);
						*((unsigned int *)b->img->pixels + b->winx * (px.y + j) + px.x + i) = col2int(col);
						SDL_UnlockSurface(b->img);
					}
				}
			}
			px.y += b->aliasing;
		}
		px.x += b->aliasing;
	}
}

void		draw_lux(t_b *b)
{
	t_px		px;
	int			i;
	int			j;
	int			r;
	t_col		col;
	t_lux 		*lux;

	lux = b->lux;
	col = init_col(b->colmax, b->colmax, b->colmax);
	while (lux)
	{
		if (vect_dot(vect_sub(lux->ori, b->cam.pos), b->cam.dir) > 0)
		{
			px = pos2px(b, lux->ori);
			if (vect_norme(vect_sub(lux->ori, b->cam.pos)) / b->vp.dist < 1)
				r = 20;
			else
				r = 20 - (int)(0.4 * vect_norme(vect_sub(lux->ori, b->cam.pos)) / b->vp.dist);
			if (r < 1)
				r = 1;
			i = -r - 1;
			while (++i <= r)
			{
				j = -r - 1;
				while (++j <= r)
				{
						// printf("id = %d\n px.x = %d\n px.y = %d\n", lux->id, px.x + i, px.y + j);
					if (px.x + i >= 0 && px.y + j >= 0 && px.y + j < b->winy && px.x + i < b->winx &&
						(i * i) + (j * j) < r * r)
					{
						b->tab_px[px.y + j][px.x + i] = px;
						b->tab_px[px.y + j][px.x + i].col = col;
						b->tab_px[px.y + j][px.x + i].id = lux->id;
					}
				}
			}
		}
		lux = lux->next;
	}
}


int main(int ac, char **av)
{
	t_b			b;


	if (ac > 2)
		return (0);
	if (ac == 2 && !ft_strcmp(av[1], "help"))
		man_help();
	else if (ac == 2 && !ft_strcmp(av[1], "help parsing"))
		help_parsing();
	else if (ac == 2 && !ft_strcmp(av[1], "usage"))
		usage();
	else if (ac == 2 && !ft_strcmp(av[1], "help obj"))
		help_obj();
	else if (ac == 2)
	{
		parse_main(&b, av[1]);
		init_b(&b);
	}
	else if (ac < 2)
	{
		init_b(&b);
		init_win(&b);
		scene5(&b);
	}
	init_win(&b);
	print_obj(b.obj);
	while (event(&b))
		rt(&b);
	SDL_DestroyWindow(b.win);
	SDL_Quit();
	return (0);
}




















