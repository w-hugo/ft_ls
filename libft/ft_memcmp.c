/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:03:26 by huweber           #+#    #+#             */
/*   Updated: 2016/11/09 16:22:33 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int							ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char			*s1x;
	unsigned char			*s2x;
	size_t					i;

	s1x = (unsigned char *)s1;
	s2x = (unsigned char *)s2;
	i = -1;
	while (++i < n)
	{
		if (s1x[i] != s2x[i])
			return (s1x[i] - s2x[i]);
	}
	return (0);
}
