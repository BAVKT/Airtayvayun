/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmercadi <vmercadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 16:03:34 by vmercadi          #+#    #+#             */
/*   Updated: 2018/02/21 14:59:24 by vmercadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RTv1.h"

/*
** Les fichiers semblent s'enregistrer masi enfait non
*/

/*
** Errors happened while parsing
*/

void	parse_err(int e, char *s)
{
	if (e == 0)
		ft_putstrcolor("Error in obj name : ", RED);
	else if (e == 1)
		ft_putstrcolor("Some double is not well formated : ", RED);
	else if (e == 2)
		ft_putstrcolor("Some vector is not well formated : ", RED);
	else if (e == 3)
		ft_putstrcolor("The file given is not a scene : ", RED);
	ft_putendl(s);
	exit (1);
}

/*
** Start the parsing
*/

void	parse_main(t_b *b, char *av)
{
            ft_putendlcolor("parse_main();", MAGENTA);
	int		fd;
	char	*s;

	if (!ft_strcmp(av, "help"))
		help_parsing();
	if ((fd = open(av, O_RDONLY)) < 0)
		parse_err(3, av);
	s = NULL;
	while (get_next_line(fd, &s) > 0)
	{
		s = ft_strtrim(s);
		if (s[0] != '#' && (s[0] != '/' && s[1] != '/'))
			parse_zob(b, s);
		ft_strdel(&s);
	}
	close(fd);
}

/*
** Check and convert a string to a vector
*/

t_v		parse_vect(char *s)
{
            ft_putendlcolor("parse_vect();", MAGENTA);
	t_v		v;
	int		i;
	int		j;
	int		p;
	char	**tab;

	tab = ft_strsplit(s, '/');
	i = -1;
	while (tab[++i])
	{
		j = -1;
		p = 0;
		while (tab[i][++j])
		{
			if (ft_isdigit(tab[i][j]) || (tab[i][j] == '.' && p == 0))
			{
				if (tab[i][j] == '.')
					p = 1;
			}
			else
				parse_err(2, s);
		}
	}
	v.x = ft_atof(tab[0]);
	v.y = ft_atof(tab[1]);
	v.z = ft_atof(tab[2]);
	free_tab((void **)tab);
	return (v);
}

/*
** Check and convert a string to a vector
*/

t_col		parse_col(char *s)
{
            ft_putendlcolor("parse_col();", MAGENTA);
	t_col	col;
	int		i;
	int		j;
	int		p;
	char	**tab;

	tab = ft_strsplit(s, '/');
	i = -1;
	while (tab[++i])
	{
		j = -1;
		p = 0;
		while (tab[i][++j])
		{
			if (ft_isdigit(tab[i][j]) || (tab[i][j] == '.' && p == 0))
			{
				if (tab[i][j] == '.')
					p = 1;
			}
			else
				parse_err(2, s);
		}
	}
	col.r = ft_atof(tab[0]);
	col.g = ft_atof(tab[1]);
	col.b = ft_atof(tab[2]);
	free_tab((void **)tab);
	return (col);
}

/*
** Check if a str is a correct double then atof() it
*/

double	parse_double(char *s)
{
	int		i;
	int		p;

	p = 0;
	i = -1;
	while (s[++i])
	{
		if (ft_isdigit(s[i]) || (s[i] == '.' && p == 0))
		{
			if (s[i] == '.')
				p = 1;
		}
		else
			parse_err(1, s);
	}
	return (ft_atof(s));
}


/*
** Pour parser des zobs
*/

void	parse_zob(t_b *b, char *av)
{
            ft_putendlcolor("parse_zob();", GREEN);
	char **tab;

	tab = ft_strsplit(av, ' ');
	if (!ft_strcmp(tab[0], "plane"))
		add_obj(b, init_plane(parse_double(tab[1]), parse_double(tab[2]),
		parse_double(tab[3]), parse_double(tab[4]), parse_col(tab[5])));
	else if (!ft_strcmp(tab[0], "sph"))
		add_obj(b, init_sph(parse_vect(tab[1]), parse_col(tab[2]), 1.0));
	else if (!ft_strcmp(tab[0], "cyl"))
		add_obj(b, init_cyl(parse_vect(tab[1]), parse_col(tab[2]), parse_vect(tab[3]), parse_double(tab[4])));
	else if (!ft_strcmp(tab[0], "cone"))
		add_obj(b, init_cone(parse_vect(tab[1]), parse_col(tab[2]), parse_vect(tab[3]), parse_double(tab[4])));
	else if (!ft_strcmp(tab[0], "lux"))
		add_lux(b, init_lux(parse_vect(tab[1]), parse_col(tab[2]), parse_col(tab[3])));
	else if (!ft_strcmp(tab[0], "amb"))
		b->amb = parse_col(tab[1]);
	else
		parse_err(0, "");
				print_col(b->amb);
	free_tab((void **)tab);
}





















