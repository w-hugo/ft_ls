/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:57:17 by huweber           #+#    #+#             */
/*   Updated: 2016/11/09 16:27:58 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*ret;

	if (!s || !(ret = (char *)malloc(len * sizeof(char) + 1)))
		return (NULL);
	ret = ft_strncpy(ret, &s[start], len);
	ret[len] = '\0';
	return (ret);
}
