/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/07 12:46:23 by huweber           #+#    #+#             */
/*   Updated: 2016/11/09 16:25:39 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strdup(const char *src)
{
	char	*ret;

	if (!(ret = (char *)malloc(ft_strlen(src) * sizeof(char) + 1)))
		return (NULL);
	return (ft_strcpy(ret, src));
}
