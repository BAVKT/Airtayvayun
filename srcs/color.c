/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:58:03 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/21 21:03:36 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"
// #include "libft.h"
// #include "colors.h"
// #include "int_2d.h"
// #include "scale.h"

unsigned int	spectrum_color(int value, int min, int max)
{
	int		c;

	// c = scale(value, create_2d(min, max), create_2d(0, 0x5F9));
	c = (value - min) * 0xffffff / (max - min);
	if (c < 0xFF)
		return (0xFF00FE - c);
	if (c < 0x1FE)
		return (0xFF0100 + ((c - 0xFF) << 8));
	if (c < 0x2FD)
		return (0xFEFF00 - ((c - 0x1FE) << 16));
	if (c < 0x3FC)
		return (0x00FF01 + (c - 0x2FD));
	if (c < 0x4FB)
		return (0x00FEFF - ((c - 0x3FC) << 8));
	return (0x0100FF + ((c - 0x4FB) << 16));
}

// int		scale(int value, t_2d min_max, t_2d new_min_max)
// {
// 	int		min;
// 	int		max;
// 	int		new_min;
// 	int		new_max;

// 	max = min_max.y;
// 	new_max = new_min_max.y;
// 	if (value == max)
// 		return (new_max);
// 	min = min_max.x;
// 	new_min = new_min_max.x;
// 	if (value == min)
// 		return (new_min);
// 	if (!(max - min))
// 		return (0);
// 	return ((value - min) * (new_max - new_min) / (max - min) + new_min);
// }

/*
** Return the color
*/

t_col		get_color(t_b *b, t_ray ray)
{
	t_col		col;
	t_lux 		*lux;
	t_ray		to_light;
	double		amp;

	if (ray.t >= b->max)
		return (init_col(0.0, 0.0, 0.0));
	// vect_normalize(&b->inter.n);
	lux = b->lux;
	col = calc_amb(b);
	to_light.ori = ray2vect(ray);
	vect_normalize(&ray.dir);
	while (lux)
	{
		to_light.dir = vect_sub(lux->ori, to_light.ori);
		if (inter_obj_lux(b, &to_light) < 0)
		{
			amp = lux->amp_cst / (1.0 + lux->amp_lin * vect_norme(to_light.dir) + lux->amp_quad * vect_norme2(to_light.dir));
			lux->light = to_light.dir;
			vect_normalize(&lux->light);
			calc_dif(lux, b->inter);
			col = color_multnb(color_add(col, lux->lum_dif), amp);
			calc_spe(lux, b->inter, vect_multnb(&ray.dir, -1));
			col = color_multnb(color_add(col, lux->lum_spe), amp);
		}
		lux = lux->next;
	}
	color_max(&col, &b->colmax);
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

void	color_max(t_col *col, double *colmax)
{
	if (col->r < 0.0)
		col->r = 0.0;
	else if (col->r > *colmax)
		*colmax = col->r;
	if (col->g < 0.0)
		col->g = 0.0;
	else if (col->g > *colmax)
		*colmax = col->g;
	if (col->b < 0.0)
		col->b = 0.0;
	else if (col->b > *colmax)
		*colmax = col->b;
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

t_col	int2col(unsigned int color)
{
	t_col col;

	col.r = (double)((color >> 16) & 255) / 255;
	col.g = (double)((color >>8) & 255) / 255;
	col.b = (double)((color) & 255) / 255;
	return (col);
}

/*
** Print color
*/

void	print_col(t_col col)
{
	printf("r = %f | g = %f | b = %f \n", col.r, col.g, col.b);
}










