/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:34:52 by huweber           #+#    #+#             */
/*   Updated: 2017/11/01 16:35:26 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				reverse_list(t_filelist **head)
{
	t_filelist	*prev;
	t_filelist	*curr;
	t_filelist	*next;

	prev = NULL;
	curr = *head;
	while (curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*head = prev;
}

void				free_file_list(t_filelist **files)
{
	t_filelist		*files_tmp;

	files_tmp = *files;
	while (*files)
	{
		files_tmp = (*files)->next;
		if ((*files)->d_name)
			free((*files)->d_name);
		if ((*files)->full_path)
			free((*files)->full_path);
		free(*files);
		*(files) = files_tmp;
	}
}

static t_filelist	*new_file_next(struct dirent *file, t_filelist *new_link)
{
	if (!(new_link->stat.st_mode & S_IRUSR) && errno == EPERM)
	{
		print_err(file->d_name, errno, 0);
		free(new_link->full_path);
		free(new_link);
		errno = 0;
		return (NULL);
	}
	new_link->from_arg = 0;
	new_link->next = NULL;
	return (new_link);
}

t_filelist			*new_file(struct dirent *file, char *path,\
	size_t *total, int single)
{
	t_filelist	*new_link;
	int			full_path_len;
	int			len;
	int			i;

	i = -1;
	if (!(new_link = (t_filelist *)malloc(sizeof(t_filelist))))
		print_err("file_list in new_file()", MALLOC_FAIL, 1);
	if (!(new_link->full_path = (char *)malloc(2048 * sizeof(char))))
		print_err("new_link->full_path in new_file()", MALLOC_FAIL, 1);
	len = ft_strlen(path);
	new_link->full_path = ft_strcpy(new_link->full_path, path);
	full_path_len = ft_strlen(new_link->full_path);
	new_link->full_path[full_path_len] = '/';
	full_path_len++;
	while (file->d_name[++i])
		new_link->full_path[full_path_len++] = file->d_name[i];
	new_link->full_path[full_path_len] = '\0';
	if ((lstat(new_link->full_path, &new_link->stat)) != 0)
		return (print_err(file->d_name, errno, 0));
	single == 0 ? *total += new_link->stat.st_blocks : 0;
	new_link->d_name = single <= 1 ?\
		ft_strdup(file->d_name) : ft_strdup(new_link->full_path);
	new_link->d_type = file->d_type;
	return (new_file_next(file, new_link));
}

void				add_file(t_filelist **filelist, t_filelist *new)
{
	t_filelist	*curr;

	if (!new)
		return ;
	if (!*filelist)
		*filelist = new;
	else
	{
		curr = *filelist;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
}
