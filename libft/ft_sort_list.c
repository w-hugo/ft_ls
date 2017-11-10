/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huweber <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:20:29 by huweber           #+#    #+#             */
/*   Updated: 2017/11/10 19:20:31 by huweber          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		bubble_sort(t_list **to_sort)
{
	t_list		*tmp;
	int			flag;

	flag = 1;
	while (flag == 1)
	{
		flag = 0;
		tmp = *to_sort;
		while (tmp && tmp->next)
		{
			if (link_cmp(e->options, tmp, tmp->next) == -1)
			{
				link_swap(&tmp, &tmp->next);
				flag = 1;
			}
			tmp = tmp->next;
		}
	}
}

t_list		*merge_list(t_list *a, t_list *b)
{
	t_list		*swap;

	swap = NULL;
	if (a == NULL)
		return (b);
	else if (b == NULL)
		return (a);
	if (_cmp(e->options, b, a) == -1)
	{
		swap = a;
		swap->next = merge_list(e, a->next, b);
	}
	else
	{
		swap = b;
		swap->next = merge_list(e, a, b->next);
	}
	return (swap);
}

void		split_list(t_list *source, t_list **front,\
	t_list **back)
{
	t_list		*fast;
	t_list		*slow;

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

void		sort_list(t_list **to_sort)
{
	t_list		*head;
	t_list		*a;
	t_list		*b;

	head = *to_sort;
	if (head == NULL || head->next == NULL)
		return ;
	split_list(head, &a, &b);
	sort_list(e, &a);
	sort_list(e, &b);
	*to_sort = merge_list(e, a, b);
}
