/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_tab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 17:22:45 by vmercadi          #+#    #+#             */
/*   Updated: 2017/11/29 17:28:06 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Search the STR in the tab. return the pointer or NULL
*/

char	*search_tab(char **tab, char *str)
{
	int i;

	if (!tab || !str)
		return (NULL);
	i = -1;
	while (tab[++i])
	{
		if (!ft_strcmp(tab[i], str))
			return (tab[i]);
	}
	return (NULL);
}
