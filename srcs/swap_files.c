/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 16:13:34 by huweber           #+#    #+#             */
/*   Updated: 2017/11/01 16:13:51 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		copy_struct(t_filelist **dst, t_filelist *src)
{
	(*dst)->full_path = src->full_path;
	(*dst)->d_name = src->d_name;
	if (src->from_arg == 0)
	{
		(*dst)->d_type = src->d_type;
	}
	(*dst)->stat = src->stat;
}

void			file_swap(t_filelist **a, t_filelist **b)
{
	t_filelist		tmp;

	tmp = **a;
	copy_struct(a, *b);
	copy_struct(b, &tmp);
}

int				file_cmp(t_options *opt, t_filelist *a, t_filelist *b)
{
	unsigned long long	timea;
	unsigned long long	timeb;
	int					ret;

	timea = opt->u == 1 ? a->stat.st_atime : a->stat.st_mtime;
	timeb = opt->u == 1 ? b->stat.st_atime : b->stat.st_mtime;
	if (opt->t)
	{
		if (timea == timeb)
		{
			timea = opt->u == 1 ?\
				a->stat.st_atimespec.tv_nsec : a->stat.st_mtimespec.tv_nsec;
			timeb = opt->u == 1 ?\
				b->stat.st_atimespec.tv_nsec : b->stat.st_mtimespec.tv_nsec;
		}
		if (timea == timeb)
			ret = ft_strcmp(a->d_name, b->d_name) > 0 ? -1 : 0;
		else
			ret = timea < timeb ? -1 : 0;
	}
	else
		ret = ft_strcmp(a->d_name, b->d_name) > 0 ? -1 : 0;
	if (opt->r)
		return (ret == -1 ? 0 : -1);
	return (ret);
}
