/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 12:21:32 by huweber           #+#    #+#             */
/*   Updated: 2016/11/09 16:29:31 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_size(unsigned int n)
{
	int				i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

static void			ft_init(int *n, int *size, int *neg, int *uintmin)
{
	if (*n == -2147483648)
	{
		*uintmin = 1;
		*n += 1;
	}
	*size = ft_size(ABS(*n));
	if (*n < 0)
	{
		*neg = 1;
		*n = ABS(*n);
		*size += 1;
	}
}

char				*ft_itoa(int n)
{
	int				size;
	int				neg;
	int				uintmin;
	char			*ret;

	neg = 0;
	uintmin = 0;
	ft_init(&n, &size, &neg, &uintmin);
	if (!(ret = (char *)malloc(size + 1 * sizeof(char))))
		return (NULL);
	ret[size] = '\0';
	while (--size >= 0)
	{
		ret[size] = (char)(n % 10 + 48);
		n = n / 10;
		if (neg == 1 && size == 1)
		{
			ret[0] = '-';
			if (uintmin == 1)
				ret[10] = '8';
			return (ret);
		}
	}
	return (ret);
}
