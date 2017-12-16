/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/07 16:13:29 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/07 06:00:09 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Affiche un tableau
*/

void	ft_print_tab(char **str)
{
	int i;

	i = 0;
	while (str[i])
		ft_putendl(str[i++]);
}
