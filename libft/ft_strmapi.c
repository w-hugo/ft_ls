/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:54:34 by huweber           #+#    #+#             */
/*   Updated: 2016/11/09 16:26:43 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*ret;

	i = -1;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	if (!(ret = (char *)malloc(len * sizeof(char) + 1)))
		return (NULL);
	while (++i < len)
		ret[i] = (*f)(i, s[i]);
	ret[i] = '\0';
	return (ret);
}
