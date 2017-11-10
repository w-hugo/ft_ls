/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 19:45:36 by huweber           #+#    #+#             */
/*   Updated: 2016/11/08 16:15:50 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;
	int		len;

	i = -1;
	if (!s || !f)
		return ;
	len = ft_strlen(s);
	while (++i < len)
		(*f)(i, &s[i]);
}
