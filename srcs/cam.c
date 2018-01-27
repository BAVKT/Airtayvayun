/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 20:43:18 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/26 21:55:21 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Refresh the dir vector
*/

void	refresh_dir(t_cam *cam, t_v v)
{
	cam->dir = v;
	cam->dirright = vect_prod(cam->dir, cam->dirup);
}

/*
** Refresh the dirrup vector
*/

void	refresh_dirup(t_cam *cam, t_v v)
{
	cam->dirup = v;
	cam->dir = vect_prod(cam->dirup, cam->dirright);
}

/*
** Refresh the dirright vector
*/

void	refresh_dirright(t_cam *cam, t_v v)
{
	cam->dirright = v;
	cam->dirup = vect_prod(cam->dirright, cam->dir);
}
