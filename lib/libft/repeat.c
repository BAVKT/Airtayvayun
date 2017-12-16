/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/13 15:21:23 by vmercadi          #+#    #+#             */
/*   Updated: 2017/08/13 15:23:27 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Return a str with a repetition of n char c
*/

char	*repeat(int n, char c)
{
	char *str;

	str = ft_strnew(n);
	while (n >= 0)
		str[n--] = c;
	return (str);
}
