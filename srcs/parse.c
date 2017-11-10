/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:55:21 by huweber           #+#    #+#             */
/*   Updated: 2017/11/10 19:15:59 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	handle_options_next(t_env *e, char *opt_list, int i)
{
	if (opt_list[i] == 'r')
		e->options->r = 1;
	else if (opt_list[i] == 'R')
		e->options->big_r = 1;
	else if (opt_list[i] == 't')
		e->options->t = 1;
	else if (opt_list[i] == 'u')
		e->options->u = 1;
	else
		print_err(&opt_list[i], ILLEGAL_OPT, 1);
}

static void	handle_options(t_env *e, char *opt_list)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(opt_list);
	while (++i < len)
	{
		if (opt_list[i] == 'a')
			e->options->a = 1;
		else if (opt_list[i] == 'd')
			e->options->d = 1;
		else if (opt_list[i] == 'f')
			e->options->f = 1;
		else if (opt_list[i] == 'l')
			e->options->l = 1;
		else if (opt_list[i] == 'g')
			e->options->g = 1;
		else if (opt_list[i] == 'G')
			e->options->big_g = 1;
		else
			handle_options_next(e, opt_list, i);
	}
}

static int	count_dirs(int ac, char **av)
{
	int		nb;
	int		i;

	i = 0;
	nb = 0;
	while (i < ac)
	{
		if (av[i][0] != '-'\
			|| (av[i][0] == '-'\
				&& ft_strlen(av[i]) == 1))
			nb++;
		i++;
	}
	return (nb == 1 ? 0 : nb);
}

void		queue_all(t_env *e, t_filelist **dirlist)
{
	t_filelist	*file_list;
	t_filelist	*dir_list;

	!e->options->f ? sort_files(e, dirlist) : 0;
	file_list = *dirlist;
	while (file_list)
	{
		if (file_list->single == 1)
		{
			e->depth++;
			queue_dir(e, file_list->full_path, file_list, file_list->single);
		}
		file_list = file_list->next;
	}
	dir_list = *dirlist;
	while (dir_list)
	{
		if (dir_list->single == 0)
		{
			queue_dir(e, dir_list->full_path, dir_list, dir_list->single);
			e->depth++;
		}
		dir_list = dir_list->next;
	}
	free_file_list(dirlist);
}

void		parse_args(t_env *e, int ac, char **av)
{
	int			i;
	int			flag;
	t_filelist	*dirlist;

	i = 0;
	flag = 0;
	dirlist = NULL;
	while (i < ac)
	{
		if (flag == 0 && !ft_strncmp(av[i], "-", 1)\
				&& ft_strlen(av[i]) > 1)
			handle_options(e, av[i]);
		else
		{
			args_to_list(&dirlist, av[i]);
			flag = 1;
		}
		i++;
	}
	e->nb_dirs = (ac == 0 || flag == 0) ? 0 : count_dirs(ac, av);
	if ((ac == 0 || flag == 0) && e->exit_status == 0)
		queue_dir(e, ".", NULL, 0);
	else
		queue_all(e, &dirlist);
}
