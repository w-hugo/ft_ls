/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 15:24:25 by huweber           #+#    #+#             */
/*   Updated: 2016/11/07 17:39:16 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t		i;
	size_t		srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (len == 0)
		return (dst);
	while (src[i] && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	if (srclen < len)
		while (i < len)
		{
			dst[i] = '\0';
			i++;
		}
	return (dst);
}
