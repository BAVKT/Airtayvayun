/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/19 07:48:32 by vmercadi          #+#    #+#             */
/*   Updated: 2016/12/10 13:59:16 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** p1 = premier maillon d'une liste. 	p2 = l'addr de la fonction a appliquer.
** Parcourt la liste lst en appliquant à chaque maillon la fonctionf et crée
** une nouvelle liste “fraiche” ré-sultant des applications successives.
** Si une allocation échoue, la fonction renvoie NULL.
*/

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst3;
	t_list	*lst2;

	lst3 = f(lst);
	if (lst3 == NULL)
		return (NULL);
	lst2 = lst3;
	while (lst->next)
	{
		lst = lst->next;
		lst2->next = f(lst);
		if (lst2->next == NULL)
			return (NULL);
		lst2 = lst2->next;
	}
	return (lst3);
}
