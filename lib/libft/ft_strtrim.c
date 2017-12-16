/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 03:03:51 by vmercadi          #+#    #+#             */
/*   Updated: 2017/01/19 17:52:19 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** p1 = La chaine à trimmer.
** Alloue et retourne une copie de la chaine sans les espaces blancs au debut
** et à la fin de cette chaine. On considère comme espaces blancs les
** caractères ’ ’, ’\n’ et ’\t’. Si s ne contient pas d’espaces blancs au début
** ou à la fin, la fonction renvoie une copie de s. Si fail, return NULL.
*/

static int	ft_scount(const char *s)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
	{
		i++;
		nb++;
	}
	if (s[i])
	{
		i = ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		{
			i--;
			nb++;
		}
	}
	return (ft_strlen(s) - nb);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		nb;
	char	*s2;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	nb = ft_scount(s);
	if (nb + 1 <= 0 || !(s2 = (char *)malloc(sizeof(char) * (nb + 1))))
		return (NULL);
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (j < nb)
	{
		s2[j] = s[i];
		i++;
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
