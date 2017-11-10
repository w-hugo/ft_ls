/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/06 14:47:03 by huweber           #+#    #+#             */
/*   Updated: 2016/11/07 17:50:19 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s1[i])
		i++;
	if (s1[i] == '\0')
		while (s2[j] && j < n && n != 0)
		{
			s1[i] = s2[j];
			i++;
			j++;
		}
	s1[i] = '\0';
	return (s1);
}