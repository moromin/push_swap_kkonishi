#include "ps.h"

static int	size_pivot(t_node *a, size_t size)
{
	int		*tab;
	size_t	i;

	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
	{
		write(2, "Error\n", 6);
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

static void	rb_or_rrb(t_node *b, int pivot, t_node *head)
{
	size_t	index_first;
	size_t	index_second;

	b = b->next;
	index_first = 0;
	while (b != head && b->val <= pivot)
	{
		index_first++;
		b = b->next;
	}
	b = head->prev;
	index_second = 1;
	while (b != head && b->val <= pivot)
	{
		index_second++;
		b = b->prev;
	}
	b = head;
	if (index_second < index_first)
		while (index_second-- > 0)
			reverse_rotate(b, 0, 0);
	else
		while (index_first-- > 0)
			rotate(b, 0, 0);
}

void	a_quicksort(t_node *a, t_node *b, size_t size)
{
	t_ps	count;
	int		pivot;

	init_count(&count, size);
	if (size <= 2 || sort_check_a(a, size))
		return (sorted_a_rotate(a, size));
	pivot = size_pivot(a, size);
	while (size-- > 0)
	{
		push(a, b, 1);
		count.pb++;
		// if (sort_check_a(a, size))
		// {
		// 	break ;
		// }
		// if (size == 2)
		// {
		// 	sorted_a_rotate(a, size);
		// 	break ;
		// }
	}
	b_quicksort(a, b, count.pb);
}

void	b_quicksort(t_node *a, t_node *b, size_t size)
{
	t_ps	count;
	int		pivot;

	init_count(&count, size);
	if (size <= 3 || sort_check_b(b, size))
		return (push_b_quick(a, b, size));
	pivot = size_pivot(b, size);
	while (count.pa < (size - 1) / 2)
	{
		if (b->next->val > pivot)
		{
			push(b, a, 0);
			count.pa++;
		}
		else
			rb_or_rrb(b, pivot, b);
	}
	b_quicksort(a, b, size - count.pa);
	a_quicksort(a, b, count.pa);
}
