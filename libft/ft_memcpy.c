/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:01:59 by huweber           #+#    #+#             */
/*   Updated: 2016/11/08 14:02:51 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void						*ft_memcpy(void *dst, const void *src, size_t n)
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
		i++;
	}
	return (dst);
}
