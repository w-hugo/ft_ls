/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:55:41 by huweber           #+#    #+#             */
/*   Updated: 2017/11/01 16:14:45 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		put_color(t_options *opt, t_filelist *file)
{
	if (S_ISDIR(file->stat.st_mode))
	{
		if (S_IWOTH & file->stat.st_mode)
			ft_printf("%s%s", FG_BLK, S_ISVTX & file->stat.st_mode ?\
				BG_GRN : BG_YEL);
		else
			ft_putstr(BD_CYN);
	}
	else if (S_ISCHR(file->stat.st_mode))
		ft_printf("%s%s", FG_BLU, BG_YEL);
	else if (S_ISBLK(file->stat.st_mode))
		ft_putstr(FG_BLU);
	else if (S_ISFIFO(file->stat.st_mode))
		ft_putstr(FG_YEL);
	else if (S_ISLNK(file->stat.st_mode))
		ft_putstr(FG_MAG);
	else if (S_ISSOCK(file->stat.st_mode))
		ft_putstr(FG_GRN);
	else if (S_IXUSR & file->stat.st_mode)
		ft_putstr(FG_RED);
	ft_putstr(file->d_name);
	ft_printf(S_ISLNK(file->stat.st_mode) && opt->l ? "%s" : "%s\n", C_RESET);
}

void		print_file(t_env *e, t_filelist *file)
{
	if (!e->options->l && !e->options->g && !e->options->big_g)
		ft_putendl(file->d_name);
	else if (e->options->l || e->options->g)
		print_long_format(e, file);
	else if (e->options->big_g)
		put_color(e->options, file);
}
