/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 20:41:59 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/17 21:06:10 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"


// Need remplacer les putnbr par des putfloat



/*
** Create a file scene based on the actual image
*/

void	rt2file(t_b *b)
{
	int		fd;
	t_obj	*obj;
	t_lux	*lux;

	if ((fd = open(rand(666666666), O_WRONLY | O_CREAT)) < 0)
		error(2);
	obj = b->obj;
	lux = b->lux;
	while (obj)
	{
		obj2file(obj, fd);
		obj = obj->next;
	}
	while (lux)
	{
		lux2file(lux, fd);
		lux = lux->next;
	}
	close(fd);
}

/*
** print the objs in the scene file
*/

void	obj2file(t_obj obj, int fd)
{
	ft_putnbr_fd((int), fd);
	ft_putchar_fd(',', fd);
	ft_putnbr_fd(col2int(b->tab_px[i][j].col), fd);
	ft_putchar_fd(' ', fd);
	j += b->aliasing;
	i += b->aliasing;
	ft_putchar_fd('\n', fd);
}

/*
** print the luxs in the scene file
*/

void	lux2file(t_lux *lux, int fd)
{

}
