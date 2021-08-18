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
