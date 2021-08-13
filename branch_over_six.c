#include "ps.h"

void	push_btoa(t_node *a, t_node *b, size_t size)
{
	if (size == 2 && b->next->val < b->next->next->val)
	{
		swap(b, 0, 0);
	}
	while (size-- > 0)
		push(b, a, 0);
}

size_t	node_size(t_node *a)
{
	t_node	*head;
	size_t	size;

	head = a;
	size = 0;
	a = a->next;
	while (a != head)
	{
		size++;
		a = a->next;
	}
	return (size);
}

int	sort_check_b(t_node *b, size_t size)
{
	t_node	*head;
	size_t	sort;
	size_t	i;

	head = b;
	sort = 0;
	i = 0;
	b = b->next;
	while (i < size)
	{
		if (b->next != head)
			if (b->val > b->next->val)
				sort++;
		b = b->next;
		i++;
	}
	if (sort == i)
		return (1);
	else
		return (0);
}

int	sort_check_a(t_node *a, size_t size)
{
	t_node	*head;
	size_t	sort;
	size_t	i;

	head = a;
	sort = 0;
	i = 0;
	a = a->next;
	while (i < size)
	{
		if (a->next != head)
			if (a->val < a->next->val)
				sort++;
		a = a->next;
		i++;
	}
	if (sort == i)
		return (1);
	else
		return (0);
}

void	size_over_six(t_node *a, t_node *b, size_t size)
{
	compression_main(a, size);
	a_to_b(a, b, size);
	return ;
}
