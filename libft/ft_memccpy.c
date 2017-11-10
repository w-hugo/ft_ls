/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 13:44:07 by huweber           #+#    #+#             */
/*   Updated: 2016/11/09 16:22:15 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void						*ft_memccpy(void *dst, const void *src, int c,
										size_t n)
{
	unsigned char			*dstx;
	const unsigned char		*srcx;
	size_t					i;

	i = 0;
	srcx = src;
	dstx = dst;
	while (i < n)
	{
		dstx[i] = srcx[i];
		if (srcx[i] == (unsigned char)c)
			return (&dstx[i + 1]);
		i++;
	}
	return (NULL);
}
