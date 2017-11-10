/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 15:23:28 by huweber           #+#    #+#             */
/*   Updated: 2016/11/16 19:36:44 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_atoi_space(const char *str)
{
	int				i;

	i = -1;
	while (str[++i] == ' ' || str[i] == '\t' || str[i] == '\r' ||
				str[i] == '\f' || str[i] == '\n' || str[i] == '\v')
		;
	return (ft_atoi(&str[i]));
}

int					ft_atoi(const char *str)
{
	int				len;
	int				ret;
	int				i;
	int				neg;

	len = 0;
	ret = 0;
	i = -1;
	neg = 0;
	if (str[0] == ' ' || str[0] == '\t' || str[0] == '\r' ||
			str[0] == '\f' || str[0] == '\n' || str[0] == '\v')
		return (ft_atoi_space(str));
	if ((str[0] == '+' || str[0] == '-') && str[1] >= '0' && str[1] <= '9')
	{
		if (str[0] == '-')
			neg++;
		len++;
		i++;
	}
	while (str[len] <= '9' && str[len] >= '0')
		len++;
	while (++i < len)
		ret = ret * 10 + (str[i] - '0');
	return (neg != 0 ? -ret : ret);
}
