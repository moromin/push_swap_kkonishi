/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:47:07 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/11 00:47:08 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static size_t	action_add_atob(t_node *a, t_node *b, int flag, t_ps *count)
{
	if (flag == RA)
	{
		if (count->rb_flag)
		{
			both_action(a, b, RR);
			count->rb_flag = 0;
		}
		else
		{
			rotate(a, 1, 0);
			count->ra_flag = 1;
		}
	}
	else if (flag == RB)
		count->rb_flag = 1;
	else if (flag == PB)
	{
		if (count->rb_flag)
			rotate(b, 0, 0);
		push(a, b, 1);
		count->rb_flag = 0;
	}
	return (1);
}

static size_t	action_add_btoa(t_node *a, t_node *b, int flag, t_ps *count)
{
	if (flag == RA && node_size(a) > 1)
		count->ra_flag = 1;
	else if (flag == RB && node_size(b) > 1)
	{
		if (count->ra_flag)
		{
			both_action(a, b, RR);
			count->ra_flag = 0;
		}
		else
		{
			rotate(b, 0, 0);
			count->rb_flag = 1;
		}
	}
	else if (flag == PA)
	{
		if (count->ra_flag)
			rotate(a, 1, 0);
		push(b, a, 0);
		count->ra_flag = 0;
		count->rb_flag = 0;
	}
	return (1);
}

static void	rrr_count(t_node *a, t_node *b, t_ps *count)
{
	size_t	ra_count;
	size_t	rb_count;

	ra_count = count->ra;
	rb_count = count->rb;
	if (count->rb_flag && count->atob_flag)
		rotate(b, 0, 0);
	while (ra_count != 0 && rb_count != 0)
	{
		both_action(a, b, RRR);
		ra_count--;
		rb_count--;
	}
	if (node_size(a) > 1)
		while (ra_count-- > 0)
			reverse_rotate(a, 1, 0);
	if (node_size(b) > 1)
		while (rb_count-- > 0)
			reverse_rotate(b, 0, 0);
}

void	b_to_a(t_node *a, t_node *b, size_t size)
{
	t_ps	count;

	if (size <= 2)
		return (size_two_atobtoa(a, b, size, 0));
	init_count(&count, size);
	size_pivot_double(b, size, &count);
	while (size-- > 0)
	{
		if (b->next->val < count.pivot_small)
			count.rb += action_add_btoa(a, b, RB, &count);
		else
		{
			count.pa += action_add_btoa(a, b, PA, &count);
			if (a->next->val < count.pivot_big)
				count.ra += action_add_btoa(a, b, RA, &count);
		}
	}
	if (count.ra_flag)
		rotate(a, 1, 0);
	a_to_b(a, b, count.pa - count.ra);
	rrr_count(a, b, &count);
	a_to_b(a, b, count.ra);
	b_to_a(a, b, count.rb);
}

void	a_to_b(t_node *a, t_node *b, size_t size)
{
	t_ps	count;

	if (above_two_check_a(a, size, a))
		return (swap(a, 1, 0));
	if (size <= 2 || sort_check_a(a, size))
		return (size_two_atobtoa(a, b, size, 1));
	init_count(&count, size);
	size_pivot_double(a, size, &count);
	while (size-- > 0)
	{
		if (a->next->val >= count.pivot_big)
			count.ra += action_add_atob(a, b, RA, &count);
		else
		{
			count.pb += action_add_atob(a, b, PB, &count);
			if (b->next->val >= count.pivot_small)
				count.rb += action_add_atob(a, b, RB, &count);
		}
	}
	count.atob_flag = 1;
	rrr_count(a, b, &count);
	a_to_b(a, b, count.ra);
	b_to_a(a, b, count.rb);
	b_to_a(a, b, count.pb - count.rb);
}
