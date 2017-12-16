/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 16:04:05 by vmercadi          #+#    #+#             */
/*   Updated: 2017/06/01 17:06:33 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Decale chaque caractere de str par sa valeur ascii + nb
** dans la fourchette ascii de start a end.
** 0 pour effectuer toutes les rotations
** ex : rot(0 str 32 127)
*/

void	ft_rot(int nb, char *str, int start, int end)
{
	int		i;
	char	*s;

	s = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	i = 0;
	while (str[i])
	{
		s[i] = ((str[i] + nb - start) % ((end - 1) - start)) + start;
		i++;
	}
	s[i] = '\0';
	ft_putendl(s);
	free(s);
}
