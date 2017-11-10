/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:14:20 by huweber           #+#    #+#             */
/*   Updated: 2016/11/09 16:27:34 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strrchr(const char *s, int c)
{
	int			i;
	int			x;

	x = -1;
	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c)
			x = i;
	if (s[i] == (unsigned char)c)
		x = i;
	if (x != -1)
		return ((char *)&s[x]);
	return (NULL);
}
