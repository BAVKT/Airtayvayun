/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 16:08:49 by vmercadi          #+#    #+#             */
/*   Updated: 2017/06/01 17:07:48 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Permet d'inverser les caracteres d'une chaine 1 a 1
*/

char	*ft_revstr(char *str)
{
	char	*tmp;
	int		i;
	int		x;

	i = 0;
	x = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * ft_strlen(str) + 1);
	while (str[i])
	{
		tmp[i] = str[x - i - 1];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
