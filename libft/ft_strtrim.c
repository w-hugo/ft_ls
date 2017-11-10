/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 20:08:44 by huweber           #+#    #+#             */
/*   Updated: 2016/11/09 16:28:10 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		get_size(char const *s)
{
	int			len;
	int			i;

	i = 0;
	len = ft_strlen(s) - 1;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	if (s[i] == '\0')
		return (0);
	while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
		len--;
	return (len - i + 1);
}

char			*ft_strtrim(char const *s)
{
	int			i;
	int			len;
	char		*ret;

	i = 0;
	if (!s)
		return (NULL);
	len = get_size(s);
	if (!(ret = (char *)malloc(len * sizeof(char) + 1)))
		return (NULL);
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
		i++;
	ret = ft_strcpy(ret, &s[i]);
	len = ft_strlen(ret) - 1;
	while (ret[len] == ' ' || ret[len] == '\n' || ret[len] == '\t')
		len--;
	ret[len + 1] = '\0';
	return (ret);
}
