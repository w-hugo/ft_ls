/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 11:57:52 by huweber           #+#    #+#             */
/*   Updated: 2016/11/16 20:11:50 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_word_num(char const *s, char c)
{
	int			i;
	int			d;
	int			word;

	i = 0;
	d = 0;
	word = 0;
	if (!s)
		return (0);
	while (s[i])
		if (s[i++] != c)
		{
			if (d == 0)
			{
				d = 1;
				word++;
			}
		}
		else
			d = 0;
	return (word);
}

static int		ft_word_len(const char *s, char c, int flag, int x)
{
	int			i;
	int			sw;
	int			word;
	int			len;

	i = 0;
	sw = 0;
	word = 0;
	len = 0;
	while (s[i])
		if (s[i++] != c)
		{
			if (sw == 0)
			{
				sw = 1;
				word++;
				if (word == flag && x == 0)
					return (i - 1);
			}
			if (sw == 1 && word == flag && x == 1)
				len++;
		}
		else
			sw = 0;
	return (len);
}

char			**ft_strsplit(const char *s, char c)
{
	char		**tab;
	int			wlen;
	int			end;
	int			i;
	int			j;

	i = 0;
	j = ft_word_num(s, c);
	if (!s || !(tab = (char **)malloc((j + 1) * sizeof(char *))))
		return (NULL);
	while (i < j)
	{
		wlen = ft_word_len(s, c, i + 1, 0);
		end = ft_word_len(s, c, i + 1, 1);
		tab[i] = ft_strsub(s, wlen, end);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
