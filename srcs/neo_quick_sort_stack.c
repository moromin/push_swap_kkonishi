#include "ps.h"

static int	size_pivot_double(t_node *a, size_t size, t_ps *count)
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
	return (0);
}

static size_t	action_add(t_node *a, t_node *b, int cmd, t_cmd **lst)
{
	if (cmd == RA && node_size(a) > 1)
		rotate_neo(a, b, cmd, lst);
	else if (cmd == RB && node_size(b) > 1)
		rotate_neo(b, a, cmd, lst);
	else if (cmd == PB)
		push_neo(a, b, cmd, lst);
	else if (cmd == PA)
		push_neo(b, a, cmd, lst);
	return (1);
}

static void	rrr_count(t_node *a, t_node *b, t_ps *count, t_cmd **lst)
{
	size_t	ra_count;
	size_t	rb_count;

	ra_count = count->ra;
	rb_count = count->rb;
	if (node_size(a) > 1 && node_size(b) > 1)
	{
		while (ra_count != 0 && rb_count != 0)
		{
			both_action_neo(a, b, RRR, lst);
			ra_count--;
			rb_count--;
		}
	}
	if (node_size(a) > 1)
		while (ra_count-- > 0)
			reverse_rotate_neo(a, b, RRA, lst);
	if (node_size(b) > 1)
		while (rb_count-- > 0)
			reverse_rotate_neo(b, a, RRB, lst);
}

void	b_to_a_neo(t_node *a, t_node *b, size_t size, t_cmd **lst)
{
	t_ps	count;

	if (size <= 2)
		return (size_two_btoa_neo(a, b, size, lst));
	init_count(&count, size);
	if (size_pivot_double(b, size, &count) < 0)
		return (double_node_free(a, b));
	while (size-- > 0)
	{
		if (b->next->val < count.pivot_small)
			count.rb += action_add(a, b, RB, lst);
		else
		{
			count.pa += action_add(a, b, PA, lst);
			if (a->next->val < count.pivot_big)
				count.ra += action_add(a, b, RA, lst);
		}
	}
	a_to_b_neo(a, b, count.pa - count.ra, lst);
	rrr_count(a, b, &count, lst);
	a_to_b_neo(a, b, count.ra, lst);
	b_to_a_neo(a, b, count.rb, lst);
}

void	a_to_b_neo(t_node *a, t_node *b, size_t size, t_cmd **lst)
{
	t_ps	count;

	if (above_two_check_a(a, size, a))
		return (swap_neo(a, b, SA, lst));
	if (size <= 2 || sort_check_a(a, size))
		return (size_two_atob_neo(a, b, size, lst));
	init_count(&count, size);
	if (size_pivot_double(a, size, &count) < 0)
		return (double_node_free(a, b));
	while (size-- > 0)
	{
		if (a->next->val >= count.pivot_big)
			count.ra += action_add(a, b, RA, lst);
		else
		{
			count.pb += action_add(a, b, PB, lst);
			if (b->next->val >= count.pivot_small)
				count.rb += action_add(a, b, RB, lst);
		}
	}
	rrr_count(a, b, &count, lst);
	a_to_b_neo(a, b, count.ra, lst);
	b_to_a_neo(a, b, count.rb, lst);
	b_to_a_neo(a, b, count.pb - count.rb, lst);
}
