/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/27 15:18:31 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/27 15:29:19 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** strjoin qui leaks pas
*/

char	*ft_strjoin_free(char *dst, char *src)
{
	char	*tmp;

	if (!src)
		return (dst);
	if (!dst)
		return (src);
	tmp = ft_strdup(dst);
	ft_strdel(&dst);
	dst = ft_strjoin(tmp, src);
	ft_strdel(&tmp);
	return (dst);
}
