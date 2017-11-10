/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:04:44 by huweber           #+#    #+#             */
/*   Updated: 2016/11/08 14:54:11 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	const char	*srcx;
	char		*dstx;
	size_t		i;

	i = -1;
	srcx = src;
	dstx = dst;
	if (src < dst)
		while ((int)--len >= 0)
			*(dstx + len) = *(srcx + len);
	else
		while (++i < len)
			*(dstx + i) = *(srcx + i);
	return (dstx);
}
