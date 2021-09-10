/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neo_sort_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:55 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/11 00:46:55 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	size_two_btoa_neo(t_node *a, t_node *b, size_t size, t_cmd **lst)
{
	if (size == 2)
	{
		if (b->next->val < b->next->next->val)
			swap_neo(b, a, SB, lst);
	}
	while (size-- > 0)
		push_neo(b, a, PA, lst);
}

void	size_two_atob_neo(t_node *a, t_node *b, size_t size, t_cmd **lst)
{
	if (size == 2)
	{
		if (a->next->val > a->next->next->val)
			swap_neo(a, b, SA, lst);
	}
	(void)size;
}

int	above_two_check_a(t_node *a, size_t size, t_node *head)
{
	int		x;
	int		y;
	size_t	i;

	x = a->next->val;
	y = a->next->next->val;
	if (x < y || size <= 2)
		return (0);
	i = 0;
	size = size - 2;
	a = a->next->next->next;
	if (size == 1 && !(x < a->val && y < a->val))
		return (0);
	while (i < size - 1 && a != head)
	{
		if (!(x < a->val && y < a->val))
			return (0);
		if (a->next != head)
			if (a->val > a->next->val)
				return (0);
		i++;
		a = a->next;
	}
	return (1);
}

size_t	min_index_search(t_node *a, size_t size)
{
	size_t	min;
	size_t	i;

	i = 0;
	min = a->next->index;
	a = a->next;
	while (i < size)
	{
		if (a->index < min)
			min = a->index;
		i++;
		a = a->next;
	}
	return (min);
}
