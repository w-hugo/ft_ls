/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_acl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:55:00 by huweber           #+#    #+#             */
/*   Updated: 2017/11/10 18:58:48 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static char		get_file_type(t_filelist *file)
{
	if (S_ISREG(file->stat.st_mode))
		return ('-');
	if (S_ISDIR(file->stat.st_mode))
		return ('d');
	else if (S_ISLNK(file->stat.st_mode))
		return ('l');
	else if (S_ISCHR(file->stat.st_mode))
		return ('c');
	else if (S_ISBLK(file->stat.st_mode))
		return ('b');
	else if (S_ISFIFO(file->stat.st_mode))
		return ('p');
	else if (S_ISSOCK(file->stat.st_mode))
		return ('s');
	else
		return ('-');
}

int				print_acl(t_filelist *file)
{
	acl_t		acl;
	acl_entry_t	dummy;

	acl = NULL;
	acl = acl_get_link_np(file->full_path, ACL_TYPE_EXTENDED);
	if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) != -1)
	{
		acl_free(acl);
		return (1);
	}
	acl_free(acl);
	return (0);
}

char			*get_file_mode(char *mode, struct stat stat)
{
	mode[1] = stat.st_mode & S_IRUSR ? 'r' : '-';
	mode[2] = stat.st_mode & S_IWUSR ? 'w' : '-';
	mode[3] = stat.st_mode & S_IXUSR ? 'x' : '-';
	mode[4] = stat.st_mode & S_IRGRP ? 'r' : '-';
	mode[5] = stat.st_mode & S_IWGRP ? 'w' : '-';
	mode[6] = stat.st_mode & S_IXGRP ? 'x' : '-';
	mode[7] = stat.st_mode & S_IROTH ? 'r' : '-';
	mode[8] = stat.st_mode & S_IWOTH ? 'w' : '-';
	mode[9] = stat.st_mode & S_IXOTH ? 'x' : '-';
	return (mode);
}

void			print_permissions(t_filelist *file)
{
	char	*mode;

	if (!(mode = (char *)malloc(12 * sizeof(char))))
		print_err("file mode in print_perm()", MALLOC_FAIL, 1);
	mode[0] = get_file_type(file);
	mode = get_file_mode(mode, file->stat);
	if (listxattr(file->full_path, NULL, 0, 0) > 0)
	{
		mode[10] = '@';
		mode[11] = '\0';
	}
	else if (print_acl(file) == 1)
	{
		mode[10] = '+';
		mode[11] = '\0';
	}
	else
		mode[10] = '\0';
	ft_printf("%-11s ", mode);
	free(mode);
}
