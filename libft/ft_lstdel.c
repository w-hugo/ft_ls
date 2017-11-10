/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 17:54:55 by huweber           #+#    #+#             */
/*   Updated: 2016/11/09 16:21:12 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*alx;
	t_list		*nxt;

	alx = *alst;
	if (!alx)
		return ;
	while (alx)
	{
		nxt = alx->next;
		del(alx->content, alx->content_size);
		free(alx);
		alx = nxt;
	}
	*alst = NULL;
}
