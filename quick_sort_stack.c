#include "ps.h"

// static size_t	search_min_index(t_node *a, size_t target, size_t size)
// {
// 	t_node	*head;
// 	size_t	index_first;
// 	size_t	index_second;

// 	head = a;
// 	a = a->next;
// 	index_first = 0;
// 	while (a != head && a->index > target)
// 	{
// 		index_first++;
// 		a = a->next;
// 	}
// 	a = head->prev;
// 	index_second = 0;
// 	while (a != head && a->index > target)
// 	{
// 		index_second++;
// 		a = a->prev;
// 	}
// 	if (index_second < index_first)
// 		return (size - 1 - index_second);
// 	return (index_first);
// }

// static void	half_set(t_node *a, t_node *b, size_t size)
// {
// 	size_t	origin_size;
// 	size_t	index;

// 	origin_size = size;
// 	while (size > origin_size / 2)
// 	{
// 		index = search_min_index(a, (origin_size - 1) / 2, origin_size);
// 		if (index != 0)
// 		{
// 			if (index <= (size - 1) / 2)
// 			{
// 				while (index-- > 0)
// 					rotate(a, 1, 0);
// 			}
// 			else
// 			{
// 				while (index++ < size)
// 					reverse_rotate(a, 1, 0);
// 			}
// 		}
// 		push(a, b, 1);
// 		size--;
// 	}
// }

static size_t	ra_or_rra(t_node *a, size_t count, int rflag)
{
	size_t	res;

	res = 0;
	while (count-- > 0)
	{
		if (rflag)
			reverse_rotate(a, 1, 0);
		else
		{
			rotate(a, 1, 0);
			res++;
		}
	}
	if (rflag)
		return (0);
	else
		return (res);
}

static size_t	node_rotate(t_node *a, int pivot, size_t size)
{
	t_node	*head;
	size_t	index_first;

	(void)size;
	head = a;
	a = a->next;
	index_first = 0;
	while (a != head && a->val >= pivot)
	{
		index_first++;
		a = a->next;
	}
	if (head->prev->val < pivot && index_first > 1)
		return (ra_or_rra(head, 1, 1));
	else
		return (ra_or_rra(head, index_first, 0));
}

static int	size_pivot(t_node *a, size_t size)
{
	int		*tab;
	size_t	i;

	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	storage_value(a, tab, size);
	quick_sort_array(tab, 0, size - 1);
	i = 0;
	a = a->next;
	while (i < size)
	{
		if (a->val == tab[size / 2])
			break ;
		a = a->next;
		i++;
	}
	free(tab);
	return (a->val);
}

void	b_to_a(t_node *a, t_node *b, size_t size)
{
	size_t	rb_count;
	size_t	pa_count;
	int		pivot;

	rb_count = 0;
	pa_count = 0;
	if (size == 1)
		return (push(b, a, 0));
	if (size == 2 || sort_check_b(b, size))
		return (push_btoa(a, b, size));
	pivot = size_pivot(b, size);
	while (pa_count < (size - 1) / 2)
	{
		if (b->next->val > pivot)
		{
			push(b, a, 0);
			pa_count++;
		}
		else
		{
			rotate(b, 0, 0);
			rb_count++;
		}
	}
	while (rb_count-- > 0 && node_size(a) > 1)
		reverse_rotate(b, 0, 0);
	a_to_b(a, b, pa_count);
	b_to_a(a, b, size - pa_count);
}

void	a_to_b(t_node *a, t_node *b, size_t size)
{
	size_t	pb_count;
	size_t	ra_count;
	size_t	origin_size;
	int		pivot;

	pb_count = 0;
	ra_count = 0;
	origin_size = size;
	if (size == 1 || sort_check_a(a, size))
		return ;
	pivot = size_pivot(a, size);
	while (pb_count < origin_size / 2)
	{
		if (a->next->val < pivot)
		{
			push(a, b, 1);
			pb_count++;
			size--;
		}
		else
			ra_count += node_rotate(a, pivot, size);
	}
	while (ra_count-- > 0 && node_size(a) > 1)
		reverse_rotate(a, 1, 0);
	a_to_b(a, b, size);
	b_to_a(a, b, pb_count);
}
