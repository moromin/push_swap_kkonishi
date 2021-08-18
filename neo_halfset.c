#include "ps.h"

static void	search_min_index(t_node *a, size_t target, t_node *head)
{
	size_t	index_first;
	size_t	index_second;

	a = a->next;
	index_first = 0;
	while (a != head && a->index > target)
	{
		index_first++;
		a = a->next;
	}
	a = head->prev;
	index_second = 1;
	while (a != head && a->index > target)
	{
		index_second++;
		a = a->prev;
	}
	a = head;
	if (index_second < index_first)
		while (index_second-- > 0)
			reverse_rotate(a, 1, 0);
	else
		while (index_first-- > 0)
			rotate(a, 1, 0);
}

void	half_set(t_node *a, t_node *b, size_t size, size_t count)
{
	size_t	origin_size;
	size_t	index;

	origin_size = size;
	index = (size - 1) / 2;
	while (size > origin_size / 2 && count == 0)
	{
		search_min_index(a, index, a);
		push(a, b, 1);
		size--;
	}
	if (count == 1)
		size = size / 2;
	while (size-- > 0 && count == 1)
		push(a, b, 1);
}
