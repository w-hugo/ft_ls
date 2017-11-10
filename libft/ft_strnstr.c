/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:31:28 by huweber           #+#    #+#             */
/*   Updated: 2016/11/09 17:21:44 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void			ft_init(int *i, int *k, int *x)
{
	*i = -1;
	*k = 0;
	*x = 0;
}

char				*ft_strnstr(const char *big, const char *little, size_t len)
{
	int				i;
	int				j;
	int				k;
	int				x;

	ft_init(&i, &k, &x);
	j = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)&big[0]);
	while (big[++i] && i < (int)len && i < (int)ft_strlen(big))
	{
		if (big[i] != little[k])
		{
			x++;
			i = x;
			k = 0;
		}
		if (big[i] == little[k])
		{
			k++;
			if (k == j)
				return ((char *)&big[i - k + 1]);
		}
	}
	return (NULL);
}
