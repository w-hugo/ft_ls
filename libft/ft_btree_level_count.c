/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_apply_by_level.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 15:53:43 by huweber           #+#    #+#             */
/*   Updated: 2016/11/16 19:06:56 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_btree_level_count(t_btree *root)
{
	if (!root)
		return (0);
	return (ft_max(ft_btree_level_count(root->left),
					ft_btree_level_count(root->right)) + 1);
}
