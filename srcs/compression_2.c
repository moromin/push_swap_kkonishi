/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:40 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/11 00:46:41 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	init_count(t_ps *count, size_t size)
{
	count->origin = size;
	count->pa = 0;
	count->pb = 0;
	count->ra = 0;
	count->rb = 0;
	count->pivot_big = 0;
	count->pivot_small = 0;
	count->ra_flag = 0;
	count->rb_flag = 0;
	count->atob_flag = 0;
}

static size_t	search_main(int *tab, int target, size_t size)
{
	size_t	midid;
	size_t	highid;
	size_t	lowid;

	lowid = 0;
	highid = size - 1;
	while (lowid <= highid)
	{
		midid = (lowid + highid) / 2;
		if (tab[midid] == target)
			break ;
		else if (tab[midid] < target)
			lowid = midid + 1;
		else
			highid = midid - 1;
	}
	return (midid);
}

void	binary_search(t_node *a, size_t size, int *tab)
{
	t_node	*head;

	head = a;
	a = a->next;
	while (a != head)
	{
		a->index = search_main(tab, a->val, size);
		a = a->next;
	}
}

void	size_pivot_double(t_node *a, size_t size, t_ps *count)
{
	size_t	min_index;
	size_t	i;

	min_index = min_index_search(a, size);
	i = 0;
	a = a->next;
	while (i < size)
	{
		if (a->index == min_index + (size / 3))
			count->pivot_small = a->val;
		else if (a->index == min_index + (size * 2 / 3))
			count->pivot_big = a->val;
		a = a->next;
		i++;
	}
}
