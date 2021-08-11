#include "ps.h"

static size_t	min_search(t_node *a)
{
	t_node	*head;
	int		min;
	size_t	res;

	head = a;
	a = a->next;
	min = a->val;
	while (a != head)
	{
		if (min > a->val)
			min = a->val;
		a = a->next;
	}
	a = head->next;
	res = 1;
	while (a != head)
	{
		if (a->val == min)
			break ;
		res++;
		a = a->next;
	}
	return (res);
}

static void	push_branch(t_node *a, t_node *b, size_t min_index, size_t size)
{
	if (min_index == size)
		reverse_rotate(a, 1, 0);
	else if (min_index == 2)
		swap(a, 1, 0);
	else if (min_index == size - 1)
	{
		reverse_rotate(a, 1, 0);
		reverse_rotate(a, 1, 0);
	}
	else if (min_index == 3 && size > 4)
	{
		rotate(a, 1, 0);
		rotate(a, 1, 0);
	}
	else if (min_index == 4 && size > 5)
	{
		reverse_rotate(a, 1, 0);
		reverse_rotate(a, 1, 0);
	}
	push(a, b, 1);
}

void	size_until_six(t_node *a, t_node *b, size_t size)
{
	size_t	push_num;
	size_t	min_index;
	size_t	i;

	push_num = size - 3;
	i = 0;
	while (i < push_num)
	{
		min_index = min_search(a);
		push_branch(a, b, min_index, size--);
		i++;
	}
	size_three(a);
	while (push_num-- > 0)
		push(b, a, 0);
}
