/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 14:15:32 by vmercadi          #+#    #+#             */
/*   Updated: 2017/12/20 15:31:01 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	parse(t_b *b, t_pars p)
{
	while ();
}


/*
** Check if the str is correct to assign in a vect
*/

t_vect		*check_vect(char *str)
{
	t_vect	v;
	int		i;

	i = -1;
	while (str[i++])
	{
		if (str[i] != '')
	}
}

/*
** Return the str without the tag (<lol> </lol>)
*/

char	*rm_tag(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i] && str[i] != '>')
		i++;
	j = i;
	while (str[i] && str[i] != '<')
		i++;
	return (tmp);
}







































