/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:35:12 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/16 19:43:52 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Start the parsing
*/

void	parse_main(t_b *b, char *av)
{
	int		i;
	int		fd;
	char	*s;

	b->pars = parse_init();
	if (!ft_strcmp(av, "usage"))
		parse_error(2);
	if ((fd = open(av, O_RDONLY)) < 0)
		error(3);
	s = NULL;
	while (get_next_line(fd, &s) > 0)
	{
		s = ft_strtrim(s);
		if (s[0] != '#' && (s[0] != '/' && s[1] != '/'))
			parse_redirect(b->pars, s);
		free(s);
	}
	close(fd);
}

/*
** Init the lists in s_pars
*/

t_pars		*parse_init()
{
	t_pars pars;

	pars.v = (t_vl *)malloc(sizeof(t_vl));
	pars->v = NULL;
	pars->v->next = NULL;
	pars.vt = (t_vl *)malloc(sizeof(t_vl));
	pars->vt = NULL;
	pars->vt->next = NULL;
	pars.vn = (t_vl *)malloc(sizeof(t_vl));
	pars->vn = NULL;
	pars->vn->next = NULL;
	return (&pars);
}

/*
** Errors for parsing
*/

void	parse_error(int e, char *s)
{
	if (!s)
		s = ft_strdup(" ");
	if (e == 0)
		ft_putendlcolor("ERROR", RED);
	else if (e == 2)
		ft_putendl("./RTv1 exemple.obj");
	else if (e == 3)
		ft_putendl("Le fichier est vide ou n'existe pas.");
	else if (e == 4)
		ft_putstr("Erreur formatage à : ");
	else if (e == 5)
		ft_putstr("Mauvais nombre d'arguments pour la face : ");
	if (s)
		ft_putendl(s);
	exit(0);
}

/*
** Redirect to the parsor needed (v, vt, vn, f, mtl)
*/

void	parse_redirect(t_pars *pars, char *s)
{
	char **tab;

	if (!(ft_strstr(s, "mtl")))
		parse_mtl(s);
	tab = ft_strsplit(tab, ' ');
	if (tab_len(tab) > 4)
		parse_error(4, s);
	if (!(ft_strcmp(tab[0], "v")))
		parse_som(pars->v, tab);
	else if (!(ft_strcmp(tab[0], "vt")))
		parse_som(pars->vt, tab);
	else if (!(ft_strcmp(tab[0], "vn")))
		parse_som(pars->vn, tab);
	else if (!(ft_strcmp(tab[0], "f")))
		parse_f(pars, tab);
	else
		parse_error(0);
}

/*
** Parse and add the line to v list
*/

void	parse_som(t_v v, char **tab)
{
	double	nb1;
	double	nb2;
	double	nb3;
	t_v		*tmp;

	tmp = v;
	while (tmp)
		tmp = tmp->next;
	if (!(nb1 = ft_atof(tab[1])))
		nb1 = 0;
	if (!(nb2 = ft_atof(tab[2])))
		nb2 = 0;
	if (!(nb3 = ft_atof(tab[3])))
		nb3 = 0;
	tmp = init_vectl(nb1, nb2, nb3);
	tmp = tmp->next;
	tmp->next = NULL;
}

/*
** Check if the line got all we need to fill the s_face struct
*/

void	check_f(char **tab)
{
	char	*ntab;
	int		i;
	int		j;

	if (tab_len(tab) != 4)
		parse_error(5, ft_implode(tab, ' '));
	j = -1;
	while (++j < 4)
	{
		ntab = ft_strsplit(tab[j], '/')
		i = -1;
		while (ntab[++i])
			if (!ft_isnum(ntab[i]) && ntab[i])
				parse_error(4, s);
	}
}

/*
** Parsing for f lines
*/

void	parse_f(t_pars *pars, char **tab)
{
	check_f(tab);
}

/*
** Return 1 if string only contain digit
*/

int		ft_isnum(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	return (1);
}

/*
** Implode a tab in an str separating with the given char
*/

char	*ft_implode(char **tab, char c)
{
	int 	size;
	int		i;
	int		j;
	int		k;
	char	*str;

	i = -1;
	k = -1;
	size = tab_len(tab);
	str = ft_strnew(0);
	while (tab[++i])
	{
		j = -1;
		while (tab[i][++j])
			str[++k] = tab[i][j];
		str[++k] = c;
	}
	str[++k] = '\0';
	return (str);
}

/*
** Parse for the mtl files
*/

void	parse_mtl(char *s)
{

}





























