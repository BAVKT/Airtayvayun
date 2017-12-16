/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbrcolor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 16:27:49 by vmercadi          #+#    #+#             */
/*   Updated: 2017/01/19 16:30:30 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Permet de mettre un chiffre en couleur.
*/

void	ft_putnbrcolor(int i, char *color)
{
	ft_putstr(color);
	ft_putnbrendl(i);
	ft_putstr(RESET);
}
