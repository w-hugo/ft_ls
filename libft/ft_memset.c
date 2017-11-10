/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 14:54:38 by huweber           #+#    #+#             */
/*   Updated: 2016/11/08 14:57:35 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	char		*ret;
	size_t		i;

	i = -1;
	ret = b;
	while (++i < len)
		ret[i] = (unsigned char)c;
	return (ret);
}
