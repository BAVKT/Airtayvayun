/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 16:17:07 by vmercadi          #+#    #+#             */
/*   Updated: 2017/06/01 17:11:13 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Initialise le tableau.
*/

char	**ft_init_tab(int size)
{
	char	**tab;
	int		i;

	i = 0;
	tab = (char **)malloc(sizeof(char *) * size + 1);
	while (i < size)
	{
		tab[i] = (char *)malloc(sizeof(char) * size + 1);
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
