/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 14:55:14 by huweber           #+#    #+#             */
/*   Updated: 2017/11/01 15:46:18 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		bubble_sort(t_env *e, t_filelist **to_sort)
{
	t_filelist		*tmp;
	int				flag;

	flag = 1;
	while (flag == 1)
	{
		flag = 0;
		tmp = *to_sort;
		while (tmp && tmp->next)
		{
			if (file_cmp(e->options, tmp, tmp->next) == -1)
			{
				file_swap(&tmp, &tmp->next);
				flag = 1;
			}
			tmp = tmp->next;
		}
	}
}

t_filelist	*merge_sorted_list(t_env *e, t_filelist *a, t_filelist *b)
{
	t_filelist		*swap;

	swap = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (file_cmp(e->options, b, a) == -1)
	{
		swap = a;
		swap->next = merge_sorted_list(e, a->next, b);
	}
	else
	{
		swap = b;
		swap->next = merge_sorted_list(e, a, b->next);
	}
	return (swap);
}

void		split_list(t_filelist *source, t_filelist **front,\
	t_filelist **back)
{
	t_filelist		*fast;
	t_filelist		*slow;

	if (source == NULL || source->next == NULL)
	{
		*front = source;
		*back = NULL;
	}
	else
	{
		slow = source;
		fast = source->next;
		while (fast != NULL)
		{
			fast = fast->next;
			if (fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}
		*front = source;
		*back = slow->next;
		slow->next = NULL;
	}
}

void		sort_files(t_env *e, t_filelist **to_sort)
{
	t_filelist		*head;
	t_filelist		*a;
	t_filelist		*b;

	head = *to_sort;
	if (head == NULL || head->next == NULL)
		return ;
	split_list(head, &a, &b);
	sort_files(e, &a);
	sort_files(e, &b);
	*to_sort = merge_sorted_list(e, a, b);
}
