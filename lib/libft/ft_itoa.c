/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 05:02:21 by vmercadi          #+#    #+#             */
/*   Updated: 2017/01/07 16:23:06 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	int		i;
	long	n2;
	char	*s;
	char	buf[42];

	i = 0;
	n2 = (n < 0) ? -(long)n : n;
	while (n2 > 0)
	{
		buf[i++] = (n2 % 10) + 48;
		n2 /= 10;
	}
	if (n == 0)
		buf[i++] = '0';
	if (n < 0)
		buf[i++] = '-';
	if (i + 1 <= 0 || !(s = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	s[i] = '\0';
	while (--i >= 0)
		s[n2++] = buf[i];
	return (s);
}
