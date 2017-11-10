/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 15:50:41 by huweber           #+#    #+#             */
/*   Updated: 2017/04/18 17:12:31 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void				*ft_realloc(void *p, size_t size)
{
	void			*tmp;

	if (!p || !size || !(tmp = ft_strnew(size)))
		return (NULL);
	ft_strcpy(tmp, p);
	ft_memdel(&p);
	return (tmp);
}
