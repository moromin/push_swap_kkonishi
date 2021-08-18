#include "ps.h"

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
	
	// size_t	sum;
	// size_t	i;
	// t_node	*head;

	// i = 0;
	// sum = 0;
	// head = a;
	// a = a->next;
	// while (i < size)
	// {
	// 	sum += a->index;
	// 	i++;
	// 	a = a->next;
	// }
	// sum = sum / size;
	// a = head->next;
	// while (a != head)
	// {
	// 	if (a->index == sum)
	// 		break ;
	// 	a = a->next;
	// }
	return (a->val);
}

void	b_to_a(t_node *a, t_node *b, size_t size)
{
	t_ps	count;
	int		pivot;

	init_count(&count, size);
	if (size <= 2 || sort_check_b(b, size))
		return (push_btoa(a, b, size));
	pivot = size_pivot(b, size);
	while (count.pa < (size - 1) / 2)
	{
		if (b->next->val > pivot)
		{
			push(b, a, 0);
			count.pa++;
		}
		else
		{
			rotate(b, 0, 0);
			count.rb++;
		}
	}
	while (count.rb-- > 0 && node_size(a) > 1)
		if (node_size(b) != size / 2)
			reverse_rotate(b, 0, 0);
	a_to_b(a, b, count.pa);
	b_to_a(a, b, size - count.pa);
}

void	a_to_b(t_node *a, t_node *b, size_t size)
{
	t_ps	count;
	size_t	current_size;
	int		pivot;

	init_count(&count, size);
	if (size == 1 || sort_check_a(a, size))
		return ;
	pivot = size_pivot(a, size);
	while (count.pb < count.origin / 2)
	{
		if (a->next->val < pivot)
		{
			push(a, b, 1);
			count.pb++;
			size--;
		}
		else
			count.ra += node_rotate(a, pivot, size);
	}
	current_size = node_size(a);
	while (count.ra-- > 0 && node_size(a) > 1)
		if (count.origin / 2 != current_size)
			reverse_rotate(a, 1, 0);
	a_to_b(a, b, size);
	b_to_a(a, b, count.pb);
}
