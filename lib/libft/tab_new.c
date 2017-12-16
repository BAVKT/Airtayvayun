/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/26 16:36:51 by vmercadi          #+#    #+#             */
/*   Updated: 2017/11/26 17:30:45 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Init a new char* tab and set the size + 1 to NULL
*/

char	**tab_new(int size)
{
	char	**tab;
	int		i;

	i = 0;
	if (size <= 0)
		return (NULL);
	if (!(tab = (char **)malloc(sizeof(char *) * size + 1)))
		return (NULL);
	while (i < size)
		tab[i++] = ft_strnew(0);
	tab[i] = NULL;
	return (tab);
}
