/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/14 17:47:02 by vmercadi          #+#    #+#             */
/*   Updated: 2016/11/23 11:30:16 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int				i;
	unsigned char	*s2;

	s2 = (unsigned char *)s;
	i = 0;
	while (n != 0)
	{
		if (s2[i] == (unsigned char)c)
			return (&s2[i]);
		i++;
		n--;
	}
	return (NULL);
}
