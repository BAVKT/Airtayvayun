/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 00:56:03 by vmercadi          #+#    #+#             */
/*   Updated: 2016/11/26 11:48:07 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** p1 = La chaine à clear.
** Assigne la valeur ’\0’ à tous les caractères de la chaine passée en param.
*/

void	ft_strclr(char *s)
{
	if (s)
		ft_bzero(s, (int)ft_strlen(s));
}
