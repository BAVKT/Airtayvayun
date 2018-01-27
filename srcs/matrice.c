/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 16:33:39 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/26 18:29:05 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Add 2 matrices
*/

t_matrice	matrice_add(t_matrice a, t_matrice b)
{
	int			i;
	int			j;
	t_matrice	m;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			m.data[i][j] = a.data[i][j] + b.data[i][j];
	}
	return (m);
}

/*
** Sub 2 matrices
*/

t_matrice	matrice_sub(t_matrice a, t_matrice b)
{
	int			i;
	int			j;
	t_matrice	m;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			m.data[i][j] = a.data[i][j] - b.data[i][j];
	}
	return (m);
}

/*
** mult 2 matrices
*/

t_matrice	matrice_mult(t_matrice a, t_matrice b)
{
	int			i;
	int			j;
	int			k;
	t_matrice	m;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
		{
			k = -1;
			m.data[i][j] = 0;
			while (++k < 3)
				m.data[i][j] += a.data[i][k] * b.data[k][j];
		}
	}
	return (m);
}

/*
** mult 2 matrices
*/

t_matrice	matrice_multnb(t_matrice a, double nb)
{
	int			i;
	int			j;
	t_matrice	m;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (++j < 3)
			m.data[i][j] = a.data[i][j] * nb;
	}
	return (m);
}

/*
** Multiply a matrice by a vector
*/

t_v		matrice_multvect(t_matrice m, t_v v)
{
	t_v		vect;
	int		i;

	i = -1;
	vect.x = 0;
	while (++i < 3)
		vect.x += v.x * m.data[0][i];
	i = -1;
	vect.y = 0;
	while (++i < 3)
		vect.y += v.y * m.data[1][i];
	i = -1;
	vect.z = 0;
	while (++i < 3)
		vect.z += v.z * m.data[2][i];
	return (vect);
}
















