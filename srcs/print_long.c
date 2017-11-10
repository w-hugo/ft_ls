/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_long.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:55:49 by huweber           #+#    #+#             */
/*   Updated: 2017/11/10 19:17:27 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_mtime(t_env *e, struct stat stat)
{
	char		*s_date;
	time_t		t;
	char		*current_year;
	struct tm	tm;

	s_date = ctime(e->options->u == 1 ? &stat.st_atime : &stat.st_mtime);
	s_date = &s_date[4];
	t = time(NULL);
	tm = *localtime(&t);
	current_year = ft_itoa(tm.tm_year + 1900);
	if (ft_strncmp(&s_date[16], current_year, 4))
	{
		s_date[7] = ' ';
		s_date[8] = s_date[16];
		s_date[9] = s_date[17];
		s_date[10] = s_date[18];
		s_date[11] = s_date[19];
		s_date[12] = '\0';
	}
	s_date[12] = '\0';
	free(current_year);
	ft_printf("%s ", s_date);
}

void			print_link(t_filelist *file)
{
	char	*link;
	int		len;

	if ((link = (char *)malloc(2048 * sizeof(char))) == NULL)
		print_err("link in print_link()", MALLOC_FAIL, 1);
	if ((len = readlink(file->full_path, link, MAX_PATH)) < 0)
		print_err(file->d_name, errno, 0);
	else
	{
		link[len] = '\0';
		ft_printf(" -> %s\n", link);
	}
	free(link);
}

void			print_size_minmaj(t_filelist *file)
{
	if (!S_ISCHR(file->stat.st_mode) && !S_ISBLK(file->stat.st_mode))
		ft_printf("%11d ", file->stat.st_size);
	else
	{
		ft_printf("%5d,", major(file->stat.st_rdev));
		ft_printf("%5d ", minor(file->stat.st_rdev));
	}
}

void			print_long_format(t_env *e, t_filelist *file)
{
	struct passwd	*pw;
	struct group	*gr;

	pw = getpwuid(file->stat.st_uid);
	gr = getgrgid(file->stat.st_gid);
	print_permissions(file);
	ft_printf("%3d ", file->stat.st_nlink);
	if (!e->options->g)
	{
		if (pw)
			ft_printf("%-11s ", pw->pw_name);
		else
			ft_printf("%-11d ", file->stat.st_uid);
	}
	if (gr)
		ft_printf("%-13s ", gr->gr_name);
	else
		ft_printf("%-13d ", file->stat.st_gid);
	print_size_minmaj(file);
	print_mtime(e, file->stat);
	put_color(e->options, file);
	if (S_ISLNK(file->stat.st_mode))
		print_link(file);
}
