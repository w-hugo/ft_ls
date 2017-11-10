/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/16 15:29:57 by huweber           #+#    #+#             */
/*   Updated: 2016/11/16 20:12:44 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void			*ft_btree_search_item(t_btree *root, void *data_ref,
										int (*cmpf)(void *, void *))
{
	void		*save;

	save = NULL;
	if (!root)
		return (NULL);
	if (root->left)
		save = ft_btree_search_item(root->left, data_ref, cmpf);
	if (((*cmpf)(data_ref, root->item)) >= 0)
		save = root->item;
	if (!save && root->right)
		save = ft_btree_search_item(root->right, data_ref, cmpf);
	return (save);
}
