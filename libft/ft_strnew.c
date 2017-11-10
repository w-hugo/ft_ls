/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 18:49:43 by huweber           #+#    #+#             */
/*   Updated: 2016/11/09 17:24:13 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char			*ft_strnew(size_t size)
{
	size_t		i;
	char		*ret;

	i = 0;
	if (!(ret = (char *)malloc(size * sizeof(char) + 1)))
		return (NULL);
	while (i < size)
		ret[i++] = '\0';
	ret[size] = '\0';
	return (ret);
}
