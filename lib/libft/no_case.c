/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   no_case.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 15:20:43 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/13 15:49:13 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Convert normal strings to no-maj string
*/

char	*no_case(char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_strnew(ft_strlen(str));
	while (str[i])
	{
		if (is_upper(str[i]))
			tmp[i] = str[i] + 32;
		else
			tmp[i] = str[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}
