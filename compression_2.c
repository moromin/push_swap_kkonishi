#include "ps.h"

void	init_count(t_ps *count, size_t size)
{
	count->origin = size;
	count->pa = 0;
	count->pb = 0;
	count->ra = 0;
	count->rb = 0;
	count->pivot_big = 0;
	count->pivot_small = 0;
}

static size_t	search_main(int *tab, int target, size_t size)
{
	size_t	midid;
	size_t	highid;
	size_t	lowid;

	lowid = 0;
	highid = size - 1;
	while (lowid <= highid)
	{
		midid = (lowid + highid) / 2;
		if (tab[midid] == target)
			break ;
		else if (tab[midid] < target)
			lowid = midid + 1;
		else
			highid = midid - 1;
	}
	return (midid);
}

void	binary_search(t_node *a, size_t size, int *tab)
{
	t_node	*head;

	head = a;
	a = a->next;
	while (a != head)
	{
		a->index = search_main(tab, a->val, size);
		a = a->next;
	}
}
