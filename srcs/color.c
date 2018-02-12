/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:58:03 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/12 15:14:04 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Return the color
*/

t_col		get_color(t_b *b, t_ray ray)
{
	t_col		col;
	t_lux 		*lux;
	t_ray		to_light;
	double		amp;

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
		color_max(col, &b->colmax);
	}
	else
		col = init_col(0.0, 0.0, 0.0);
	return (col);
}


/*
** Add 2 colors and return the result
*/

t_col		color_add(t_col col, t_col col2)
{
	t_col tmp;

	tmp.r = col.r + col2.r;
	tmp.g = col.g + col2.g;
	tmp.b = col.b + col2.b;
	return (tmp);
}

/*
** Multiply 2 colors and return the result
*/

t_col		color_mult(t_col col, t_col col2)
{
	t_col tmp;

	tmp.r = col.r * col2.r;
	tmp.g = col.g * col2.g;
	tmp.b = col.b * col2.b;
	return (tmp);
}

/*
** Multiply a color by nb
*/

t_col		color_multnb(t_col col, double nb)
{
	t_col tmp;

	tmp.r = col.r * nb;
	tmp.g = col.g * nb;
	tmp.b = col.b * nb;
	return (tmp);
}

/*
** Saturate the color
*/

void		color_sat(t_col *col)
{
	// double	max;

	// max = (col->r > col->b) ? col->r : col->b;
	// max = (max > col->g) ? max : col->g;
	// if (max == 0)
	// {
	// 	col->r = 0;
	// 	col->g = 0;
	// 	col->b = 0;
	// }
	// else
	// {
	// 	col->r /= max;
	// 	col->g /= max;
	// 	col->b /= max;
	// }
	// if (col->r < 0.0)
	// 	col->r = 0.0;
	// if (col->g < 0.0)
	// 	col->g = 0.0;
	// if (col->b < 0.0)
	// 	col->b = 0.0;
	if (col->r > 1.0)
		col->r = 1.0;
	else if (col->r < 0.0)
		col->r = 0.0;
	if (col->g > 1.0)
		col->g = 1.0;
	else if (col->g < 0.0)
		col->g = 0.0;
	if (col->b > 1.0)
		col->b = 1.0;
	else if (col->b < 0.0)
		col->b = 0.0;

}

void	color_max(t_col col, double *colmax)
{
	if (col.r > *colmax)
		*colmax = col.r;
	if (col.g > *colmax)
		*colmax = col.g;
	if (col.b > *colmax)
		*colmax = col.b;
}

/*
** Convert a t_col to an unsigned int color
*/

unsigned int	col2int(t_col col)
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;

	r = (unsigned int)(col.r * 255.0);
	g = (unsigned int)(col.g * 255.0);
	b = (unsigned int)(col.b * 255.0);
	return ((r << 16) | (g << 8) | b);
}

/*
** Print color
*/

void	print_col(t_col col)
{
	printf("r = %f | g = %f | b = %f \n", col.r, col.g, col.b);
}










