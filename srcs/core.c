/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:54:42 by huweber           #+#    #+#             */
/*   Updated: 2017/11/10 19:07:55 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_filelist		*read_dir(t_env *e, char *path, char *fname,\
	int flag)
{
	t_filelist		*to_sort;
	DIR				*current;
	struct dirent	*file;

	errno = 0;
	to_sort = NULL;
	current = opendir(path);
	if (errno)
	{
		path = ft_strrchr(path, '/');
		path = &path[1];
		return (print_err(path, errno, 0));
	}
	while ((file = readdir(current)))
	{
		if (file->d_name[0] != '.' || e->options->a || e->options->f)
			if (!e->options->d || file->d_type == DT_DIR)
				if (flag == 0 || !strcmp(fname, file->d_name))
					add_file(&to_sort, new_file(file, path, &e->total, 0));
	}
	if (!e->options->f)
		sort_files(e, &to_sort);
	closedir(current);
	return (to_sort);
}

void			queue_dir(t_env *e, char *path, t_filelist *print, int single)
{
	t_filelist		*file_list;
	t_filelist		*head;

	e->total = 0;
	if (single == 1)
	{
		print_file(e, print);
		return ;
	}
	if (e->nb_dirs > 0)
		ft_printf(e->depth > 0 ? "\n%s:\n" : "%s:\n", path);
	if (!(file_list = read_dir(e, path, NULL, 0)))
		return ;
	head = file_list;
	e->options->l == 1 ? ft_printf("total %d\n", e->total) : 0;
	while (file_list)
	{
		print_file(e, file_list);
		file_list = file_list->next;
	}
	if (e->options->big_r && !e->options->d)
		queue_next_dir(e, head, path);
	if (head)
		free_file_list(&head);
}

void			queue_next_dir(t_env *e, t_filelist *head, char *path)
{
	char				*new_path;

	while (head)
	{
		errno = 0;
		if ((head->d_type == DT_DIR || !ft_strcmp(head->d_name, "fd"))
			&& ft_strcmp(head->d_name, ".")
			&& ft_strcmp(head->d_name, "./")
			&& ft_strcmp(head->d_name, ".."))
		{
			new_path = strjoin_path(path, head->d_name);
			e->nb_dirs++;
			e->depth++;
			queue_dir(e, new_path, NULL, 0);
			free(new_path);
		}
		head = head->next;
	}
}

int				main(int ac, char **av)
{
	t_env		*e;
	int			exit_status;

	if (!(e = (t_env *)malloc(sizeof(t_env))))
		print_err("env in main()", MALLOC_FAIL, 1);
	init_env(e);
	parse_args(e, (ac - 1), &av[1]);
	exit_status = e->exit_status;
	free_env(e);
	errno = 0;
	return (exit_status);
}
