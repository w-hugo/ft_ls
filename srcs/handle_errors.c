/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_errors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:55:06 by huweber           #+#    #+#             */
/*   Updated: 2017/11/01 15:21:59 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			*print_err(const char *err, int err_no, int quit)
{
	if (err_no == ILLEGAL_OPT)
	{
		ft_printf_fd(2,\
	"ft_ls: illegal option -- %c\nusage: ./ft_ls [-adflgGrRt] [file ...]\n"\
	, err[0]);
		exit(EXIT_FAILURE);
	}
	else if (err)
		ft_printf_fd(2, "ft_ls: %s: %s\n", err, strerror(errno));
	else
		perror("");
	if (quit == 1)
	{
		errno = 0;
		exit(EXIT_FAILURE);
	}
	errno = 0;
	return (NULL);
}
