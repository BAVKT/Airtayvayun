/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 16:58:03 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/30 16:47:12 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

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










