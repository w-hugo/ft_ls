/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:45:36 by huweber           #+#    #+#             */
/*   Updated: 2016/11/08 16:15:31 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striter(char *s, void (*f)(char *))
{
	int		i;
	int		len;

	i = -1;
	if (!s || !f)
		return ;
	len = ft_strlen(s);
	while (++i < len)
		(*f)(&s[i]);
}
