/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:02:57 by huweber           #+#    #+#             */
/*   Updated: 2017/02/27 16:13:16 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strjoin(char *s1, char const *s2)
{
	int		x;
	int		y;
	int		i;
	char	*ret;

	i = -1;
	if (!s1 || !s2)
		return (NULL);
	x = ft_strlen(s1);
	y = ft_strlen(s2);
	if (!(ret = (char *)malloc((x + y + 2) * sizeof(char))))
		return (NULL);
	while (++i < x)
		ret[i] = s1[i];
	x = -1;
	while (++x < y)
		ret[i + x] = s2[x];
	ret[i + x] = '\0';
	return (ret);
}
