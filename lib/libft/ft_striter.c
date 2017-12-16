/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 00:59:29 by vmercadi          #+#    #+#             */
/*   Updated: 2016/12/10 13:54:57 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** p1 = La chaine a itérer.		p2 = La fonction à appeler.
** Applique la fonction f à chaque caractère de la chaine de caractères passée.
** Chaque caractère est passé par adresse à la fonction f
** afin de pouvoir être modifié si nécéssaire.
*/

void	ft_striter(char *s, void (*f)(char *))
{
	int n;
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	n = ft_strlen(s);
	while (i < n)
	{
		f(&s[i]);
		i++;
	}
}
