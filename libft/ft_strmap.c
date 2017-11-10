/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:50:13 by huweber           #+#    #+#             */
/*   Updated: 2016/11/09 16:26:30 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strmap(char const *s, char (*f)(char))
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
		ret[i] = (*f)(s[i]);
	ret[i] = '\0';
	return (ret);
}
