#include "ps.h"

static void	size_three_case_reverse(t_node *b, int x, int y, int z)
{
	if (x > y && y < z && z > x)
		reverse_rotate(b, 0, 0);
	else if (x < y && y < z && z > x)
	{
		swap(b, 0, 0);
		reverse_rotate(b, 0, 0);
	}
	else if (x > y && y < z && z < x)
	{
		swap(b, 0, 0);
		rotate(b, 0, 0);
	}
	else if (x < y && y > z && z > x)
		rotate(b, 0, 0);
	else if (x < y && y > z && z < x)
		swap(b, 0, 0);
}

static void	size_three_case_b(t_node *b)
{
	int	x;
	int	y;
	int	z;

	x = b->next->val;
	y = b->next->next->val;
	z = b->next->next->next->val;
	size_three_case_reverse(b, x, y, z);
}

void	push_b_quick(t_node *a, t_node *b, size_t size)
{
	size_t	origin;

	origin = size;
	if (size == 2 && b->next->val < b->next->next->val)
		swap(b, 0, 0);
	else if (size == 3)
		size_three_case_b(b);
	while (size-- > 0)
		push(b, a, 0);
	while (origin-- > 0)
		rotate(a, 1, 0);
}

void	sorted_a_rotate(t_node *a, size_t size)
{
	if (size == 2 && a->next->val > a->next->next->val)
		swap(a, 1, 0);
	while (size-- > 0)
		rotate(a, 1, 0);
}
