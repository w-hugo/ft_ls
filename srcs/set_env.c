/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:56:01 by huweber           #+#    #+#             */
/*   Updated: 2017/11/01 16:17:02 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_env(t_env *e)
{
	if (!(e->options = (t_options *)malloc(sizeof(t_options))))
		print_err("option list in init_env()", MALLOC_FAIL, 1);
	*e->options = (t_options){0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
	e->exit_status = 0;
	e->nb_dirs = 0;
	e->depth = 0;
	e->total = 0;
}

void	free_env(t_env *e)
{
	free(e->options);
	free(e);
}
