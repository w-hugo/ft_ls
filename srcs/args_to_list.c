/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   single_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:56:08 by huweber           #+#    #+#             */
/*   Updated: 2017/11/10 18:59:08 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_filelist	*add_single_file(char *path, int is_single)
{
	t_filelist		*new_link;

	if (!(new_link = (t_filelist *)malloc(sizeof(t_filelist))))
		print_err("file_list in new_file()", MALLOC_FAIL, 1);
	new_link->full_path = ft_strdup(path);
	new_link->d_name = ft_strdup(path);
	new_link->single = is_single;
	new_link->from_arg = 1;
	new_link->next = NULL;
	lstat(path, &new_link->stat);
	return (new_link);
}

int					args_to_list(t_filelist **dirlist, char *path)
{
	struct stat		dummy;
	DIR				*dummy_dir;
	int				ret;

	ret = lstat(path, &dummy);
	if (ret == 0 && !S_ISDIR(dummy.st_mode))
		add_file(dirlist, add_single_file(path, 1));
	else if ((dummy_dir = opendir(path)) != NULL)
	{
		add_file(dirlist, add_single_file(path, 0));
		closedir(dummy_dir);
	}
	else
	{
		print_err(path, errno, 0);
		return (0);
	}
	return (1);
}
