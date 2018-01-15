/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parseur.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 20:35:12 by vmercadi          #+#    #+#             */
/*   Updated: 2018/01/15 20:51:12 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

void	parse_error(int e, char *s)
{
	if (e == 0)
		ft_putendlcolor("ERROR", RED);
	else if (e == 2)
		ft_putendl("./RTv1 exemple.obj");
	else if (e == 3)
		ft_putendl("Le fichier est vide ou n'existe pas.");
	else if (e == 4)
	{
		ft_putstr("Erreur formatage à :");
		ft_putendl(s);
	}
	exit(0);
}

/*
** Init the lists in s_pars
*/

t_pars		*parse_init()
{
	t_pars pars;

	pars.v = (t_vl *)malloc(sizeof(t_vl));
	pars->next = NULL;
	pars.vt = (t_vl *)malloc(sizeof(t_vl));
	pars->next = NULL;
	pars.vn = (t_vl *)malloc(sizeof(t_vl));
	pars->next = NULL;
	return (&pars);
}

/*
** Start the parsing
*/

void	parse_main(char *av)
{
	int		i;
	int		fd;
	char	*s;
	t_pars	*pars;

	pars = parse_init();
	if (!ft_strcmp(av, "usage"))
		parse_error(2);
	if ((fd = open(av, O_RDONLY)) < 0)
		error(3);
	s = NULL;
	while (get_next_line(fd, &s) > 0)
	{
		if (s[0] != '#' && (s[0] != '/' && s[1] != '/'))
			parse_redirect(pars, s);
		free(s);
	}
	close(fd);
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
		parse_v(pars, tab);
	else if (!(ft_strcmp(tab[0], "vt")))
		parse_vt(pars, tab);
	else if (!(ft_strcmp(tab[0], "vn")))
		parse_vn(pars, tab);
	else if (!(ft_strcmp(tab[0], "f")))
		parse_f(pars, tab);
	else
		parse_error(0);
}

/*
** Parse and add the line to v list
*/

void	parse_v(t_pars *pars, char **tab)
{
	double	nb1;
	double	nb2;
	double	nb3;

	if (!(nb1 = atof(tab[1])))
		parse_error(4, tab[1]);
	if (!(nb1 = atof(tab[2])))
		parse_error(4, tab[2]);
	if (!(nb1 = atof(tab[3])))
		parse_error(4, tab[3]);
	pars->v = vect_init(nb1, nb2, nb3);
	pars->v->next = NULL;
}

/*
** Parse and add the line to vt list
*/

void	parse_vt(t_pars *pars, char **tab)
{
	double	nb1;
	double	nb2;
	double	nb3;

	if (!(nb1 = atof(tab[1])))
		parse_error(4, tab[1]);
	if (!(nb1 = atof(tab[2])))
		parse_error(4, tab[2]);
	if (!(nb1 = atof(tab[3])))
		parse_error(4, tab[3]);
	pars->vt = vect_init(nb1, nb2, nb3);
	pars->vt->next = NULL;
}

/*
** Parse and add the line to vn list
*/

void	parse_vn(t_pars *pars, char **tab)
{
	double	nb1;
	double	nb2;
	double	nb3;

	if (!(nb1 = atof(tab[1])))
		parse_error(4, tab[1]);
	if (!(nb1 = atof(tab[2])))
		parse_error(4, tab[2]);
	if (!(nb1 = atof(tab[3])))
		parse_error(4, tab[3]);
	pars->vn = vect_init(nb1, nb2, nb3);
	pars->vn->next = NULL;
}

/*
** Check if the line got all we need to fill the s_face struct
*/

void	check_f(char **tab)
{
	char	*ntab;
	int		i;
	int		j;

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
	{
		if (ft_isdigit(str[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

/*
** Parse for the mtl files
*/

void	parse_mtl(char *s)
{

}





























