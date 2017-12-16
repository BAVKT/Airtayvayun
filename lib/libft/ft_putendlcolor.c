/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendlcolor.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 19:16:23 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/27 15:29:30 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendlcolor(char *str, char *color)
{
	ft_putstr(color);
	ft_putstr(str);
	ft_putchar('\n');
	ft_putstr(RESET);
}
