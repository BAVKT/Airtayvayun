/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 02:22:48 by vmercadi          #+#    #+#             */
/*   Updated: 2017/01/07 16:39:36 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** p1 = La chaine dans laquelle chercher le tronçon à copier.
** p2 = L’index dans la chaine de caractères où débute le tronçon à copier.
** p3 = La longueur du tronçon à copier.
** Alloue et retourne la copie “fraiche” d’un tronçon de la chaine. Le tronçon
** commence à l’index start et à pour longueur len. Si start et len ne désignent
** pas un tronçon de chaine valide, le comportement est indéterminé.
** Si l’allocation échoue, lafonction renvoie NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;

	i = 0;
	if (!s || start >= ft_strlen(s))
		return (NULL);
	if (!(s2 = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] && i < len)
		s2[i++] = s[start++];
	s2[len] = '\0';
	if (s2)
		return (s2);
	return (NULL);
}
