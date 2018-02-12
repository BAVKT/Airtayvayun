/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjeanner <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 01:24:43 by tjeanner          #+#    #+#             */
/*   Updated: 2018/02/06 15:02:18 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <math.h>

double		ft_atof(char *s)
{
	int		i;
	int		j;
	double	res;

	res = (double)atoi(s);
	if (ft_strchr(s, '.') && (i = ft_strchr(s, '.') - s) != 0)
	{
		j = 1;
		while (s[++i] && ft_isdigit(s[i]))
		{
			res += (res >= 0) ? ((double)(s[i] - '0') * pow(10, 0 - j)) :
				-1.0 * ((double)(s[i] - '0') * pow(10, 0 - j));
			j++;
		}
	}
	return (res);
}
