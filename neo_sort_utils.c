#include "ps.h"

void	size_two_atobtoa(t_node *a, t_node *b, size_t size, int flag)
{
	if (size == 2)
	{
		if (flag == 1 && a->next->val > a->next->next->val)
			swap(a, 1, 0);
		else if (flag == 0 && b->next->val < b->next->next->val)
			swap(b, 0, 0);
	}
	if (flag == 0)
		while (size-- > 0)
			push(b, a, 0);
}

int	above_two_check_a(t_node *a, size_t size, t_node *head)
{
	int		x;
	int		y;
	size_t	i;

	x = a->next->val;
	y = a->next->next->val;
	if (x < y || size <= 2)
		return (0);
	i = 0;
	size = size - 2;
	a = a->next->next->next;
	if (size == 1 && !(x < a->val && y < a->val))
		return (0);
	while (i < size - 1 && a != head)
	{
		if (!(x < a->val && y < a->val))
			return (0);
		if (a->next != head)
			if (a->val > a->next->val)
				return (0);
		i++;
		a = a->next;
	}
	return (1);
}
