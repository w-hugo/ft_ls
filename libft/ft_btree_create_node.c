/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 14:32:53 by huweber           #+#    #+#             */
/*   Updated: 2016/11/16 20:12:38 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_btree			*ft_btree_create_node(void *item)
{
	t_btree		*tree;

	tree = NULL;
	tree = (t_btree *)malloc(sizeof(t_btree));
	if (tree)
	{
		tree->item = item;
		tree->left = NULL;
		tree->right = NULL;
	}
	return (tree);
}
