/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/20 18:35:17 by huweber           #+#    #+#             */
/*   Updated: 2017/06/05 22:16:31 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		hex_to_int(char *color)
{
	unsigned int	hex;
	int				i;

	hex = 0;
	i = color[0] == '\t' ? 1 : 0;
	if (color[i] == '0' && color[i + 1] == 'x')
	{
		i += 2;
		while (color[i] != ' ' && color[i])
		{
			hex = hex << 4;
			if (color[i] - '0' >= 0 && color[i] - '0' <= 9)
				hex = hex | (color[i] - '0');
			else if (color[i] - 'A' >= 0 && color[i] - 'A' <= 5)
				hex = hex | (color[i] - 'A') + 10;
			else if (color[i] - 'a' >= 0 && color[i] - 'a' <= 5)
				hex = hex | (color[i] - 'a') + 10;
			else
				return (hex);
			i++;
		}
	}
	return (hex);
}
