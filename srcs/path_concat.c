/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_concat.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:55:32 by huweber           #+#    #+#             */
/*   Updated: 2017/11/01 16:26:21 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*strjoin_path(char *old_path, char *d_name)
{
	char	*new_path;
	int		len;
	int		i;

	i = -1;
	if (!(new_path = (char *)malloc(2048 * sizeof(char))))
		print_err("path concat in strjoin_path()", MALLOC_FAIL, 1);
	new_path = ft_strcpy(new_path, old_path);
	len = ft_strlen(new_path);
	if (ft_strcmp(old_path, "/"))
	{
		new_path[len] = '/';
		len++;
	}
	while (d_name[++i])
		new_path[len++] = d_name[i];
	new_path[len] = '\0';
	return (new_path);
}

char	*get_file_path(char *path)
{
	int		i;
	int		j;
	int		flag;
	char	*file_path;

	j = 0;
	i = -1;
	flag = 0;
	if (!(file_path = (char *)malloc(2048 * sizeof(char))))
		print_err("file_path in get_file_path()", MALLOC_FAIL, 1);
	file_path = ft_strcpy(file_path, path);
	while (file_path[++i])
		if (file_path[i] == '/' && file_path[i + 1])
			flag++;
	if (flag > 0)
	{
		i = -1;
		while (file_path[++i])
			if (file_path[i] == '/')
				if (++j == flag)
					break ;
		file_path = ft_strcpy(file_path, &path[i + 1]);
	}
	return (file_path);
}

char	*get_dir_path_next(char *path, char *dir_path, int j, int k)
{
	int	i;

	i = -1;
	while (path[++i])
		if (path[i] == '/')
		{
			if (++k == j && path[i + 1])
				break ;
		}
	if (k > 0 && j > 0)
		dir_path[i] = '\0';
	else
		dir_path = ft_strcpy(dir_path, ".\0");
	return (dir_path);
}

char	*get_dir_path(char *path, int single)
{
	int		i;
	int		j;
	int		k;
	char	*dir_path;

	i = -1;
	j = 0;
	k = 0;
	if (!(dir_path = (char *)malloc(2048 * sizeof(char))))
		print_err("dir_path in get_dir_path()", MALLOC_FAIL, 1);
	dir_path = ft_strcpy(dir_path, path);
	while (path[++i])
		if (path[i] == '/')
			j++;
	return (get_dir_path_next(path, dir_path, j, k));
	(void)single;
}
