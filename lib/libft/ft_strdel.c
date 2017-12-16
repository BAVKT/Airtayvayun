/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 00:46:51 by vmercadi          #+#    #+#             */
/*   Updated: 2016/11/29 09:55:16 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** p1 = L'adresse de la chaine à libérer.
** Free uen chaine de caractère et met son pointeur à NULL.
*/

void	ft_strdel(char **s)
{
	if (s && *s)
		ft_memdel((void **)s);
}
