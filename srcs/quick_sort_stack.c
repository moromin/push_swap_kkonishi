#include "ps.h"

// static int	size_pivot_double(t_node *a, size_t size, t_ps *count)
// {
// 	int		*tab;
// 	size_t	i;

// 	tab = (int *)malloc(sizeof(int) * size);
// 	if (!tab)
// 		return (-1);
// 	storage_value(a, tab, size);
// 	quick_sort_array(tab, 0, size - 1);
// 	i = 0;
// 	a = a->next;
// 	while (i < size)
// 	{
// 		if (a->val == tab[size / 3])
// 			count->pivot_small = a->val;
// 		else if (a->val == tab[size * 2 / 3])
// 			count->pivot_big = a->val;
// 		a = a->next;
// 		i++;
// 	}
// 	free(tab);
// 	return (0);
// }

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

static size_t	action_add(t_node *a, t_node *b, int flag)
{
	if (flag == RA && node_size(a) > 1)
		rotate(a, 1, 0);
	else if (flag == RB && node_size(b) > 1)
		rotate(b, 0, 0);
	else if (flag == PB)
		push(a, b, 1);
	else if (flag == PA)
		push(b, a, 0);
	return (1);
}

static void	rrr_count(t_node *a, t_node *b, size_t ra_count, size_t rb_count)
{
	if (node_size(a) > 1 && node_size(b) > 1)
	{
		while (ra_count != 0 && rb_count != 0)
		{
			both_action(a, b, RRR);
			ra_count--;
			rb_count--;
		}
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
	if (size_pivot_double(b, size, &count) < 0)
		return (double_node_free(a, b));
	while (size-- > 0)
	{
		if (b->next->val < count.pivot_small)
			count.rb += action_add(a, b, RB);
		else
		{
			count.pa += action_add(a, b, PA);
			if (a->next->val < count.pivot_big)
				count.ra += action_add(a, b, RA);
		}
	}
	a_to_b(a, b, count.pa - count.ra);
	rrr_count(a, b, count.ra, count.rb);
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
	if (size_pivot_double(a, size, &count) < 0)
		return (double_node_free(a, b));
	while (size-- > 0)
	{
		if (a->next->val >= count.pivot_big)
			count.ra += action_add(a, b, RA);
		else
		{
			count.pb += action_add(a, b, PB);
			if (b->next->val >= count.pivot_small)
				count.rb += action_add(a, b, RB);
		}
	}
	rrr_count(a, b, count.ra, count.rb);
	a_to_b(a, b, count.ra);
	b_to_a(a, b, count.rb);
	b_to_a(a, b, count.pb - count.rb);
}
