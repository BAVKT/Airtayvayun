/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:03:56 by vmercadi          #+#    #+#             */
/*   Updated: 2016/12/04 22:30:20 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	s1 = (char *)dst;
	s2 = (char *)src;
	i = 0;
	if (s1 > s2)
	{
		while (i < n)
		{
			s1[n - i - 1] = s2[n - i - 1];
			i++;
		}
	}
	else if (s2 > s1)
	{
		while (i < n)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (s1);
}
