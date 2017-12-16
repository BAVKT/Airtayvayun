/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 09:18:40 by vmercadi          #+#    #+#             */
/*   Updated: 2017/07/27 15:29:17 by vmercadi         ###   ########.fr       */
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

/*
** Return the block corresponding to the fd.
** If fd haven't been seen before, create a block.
*/

t_lst	*crema(int fd, t_lst *lst)
{
	if (lst)
	{
		while (lst)
		{
			if (lst->fd == fd)
				return (lst);
			if (lst->next)
				lst = lst->next;
			else
				break ;
		}
		lst->next = (t_lst *)malloc(sizeof(t_lst));
		lst = lst->next;
	}
	else
		lst = (t_lst *)malloc(sizeof(t_lst));
	lst->fd = fd;
	lst->str = ft_strnew(0);
	lst->next = NULL;
	return (lst);
}

/*
** Read and fill the line
*/

int		rd(t_lst *lst, char **line)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	char	*tmp;

	ret = 1;
	while (ret > 0)
	{
		if ((tmp = ft_strchr(lst->str, '\n')))
		{
			*tmp = '\0';
			*line = ft_strdup(lst->str);
			ft_memmove(lst->str, tmp + 1, ft_strlen(tmp + 1) + 1);
			return (1);
		}
		ret = read(lst->fd, buf, BUFF_SIZE);
		buf[ret] = '\0';
		lst->str = ft_strjoin_free(lst->str, buf);
	}
	if (!(ret <= 0 && ft_strlen(lst->str) >= 1))
		return (0);
	*line = ft_strdup(lst->str);
	ft_strdel(&lst->str);
	lst->str = ft_strnew(0);
	return (1);
}

/*
** Create list and start the gnl
*/

int		get_next_line(int const fd, char **line)
{
	static t_lst	*firstm;
	t_lst			*lst;

	if (fd < 0 || !line || read(fd, NULL, 0) < 0)
		return (-1);
	if (!firstm)
	{
		firstm = crema(fd, firstm);
		lst = firstm;
	}
	else
		lst = crema(fd, firstm);
	return (rd(lst, line));
}
