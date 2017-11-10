/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/05 16:42:14 by huweber           #+#    #+#             */
/*   Updated: 2016/11/07 16:51:13 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strncmp(char *s1, char *s2, size_t n)
{
	size_t	j;

	j = -1;
	if (n == 0 && (!s1 || !s2))
		return (0);
	while ((s2[++j] || s1[j]) && j < n)
	{
		if (s1[j] != s2[j])
			return ((unsigned char)s1[j] - (unsigned char)s2[j]);
	}
	return (0);
}
