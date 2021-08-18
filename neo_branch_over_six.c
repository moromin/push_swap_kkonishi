#include "ps.h"

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
	while (i < size - 1)
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
	while (i < size - 1)
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

void	visualize_node(t_node *a, t_node *b)
{
	t_node	*head_a;
	t_node	*head_b;
	size_t	i;

	head_a = a;
	head_b = b;
	i = 0;
	a = a->next;
	printf("-------\n");
	while (a != head_a)
	{
		i++;
		printf("a[%lu]:%d\n", a->index, a->val);
		a = a->next;
	}
	i = 0;
	b = b->next;
	printf("-------\n");
	while (b != head_b)
	{
		i++;
		printf("b[%lu]:%d\n", b->index, b->val);
		b = b->next;
	}
	printf("-------\n");
}

void	size_over_six(t_node *a, t_node *b, size_t size)
{
	compression_main(a, size);
	a_to_b_neo(a, b, size);
	// visualize_node(a, b);
	return ;
}
