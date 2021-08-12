#include "ps.h"

static void	swap_value(int *a, int *b)
{
	int	t;

	t = *a;
	*a = *b;
	*b = t;
}

static size_t	partition(int tab[], size_t l, size_t r)
{
	int		pivot;
	size_t	i;
	size_t	j;

	pivot = tab[r];
	i = l;
	j = l;
	while (j < r)
	{
		if (tab[j] <= pivot)
		{
			swap_value(&tab[i], &tab[j]);
			i++;
		}
		j++;
	}
	swap_value(&tab[i], &tab[r]);
	return (i);
}

static void	quick_sort_array(int tab[], size_t l, size_t r)
{
	size_t	pivot;

	if (l < r)
	{	
		pivot = partition(tab, l, r);
		if (pivot != 0)
			quick_sort_array(tab, l, pivot - 1);
		quick_sort_array(tab, pivot + 1, r);
	}
}

static void	storage_value(t_node *a, int *tab)
{
	size_t	i;
	t_node	*head;

	i = 0;
	head = a;
	a = a->next;
	while (a != head)
	{
		tab[i] = a->val;
		i++;
		a = a->next;
	}
}

void	compression_main(t_node *a, size_t size)
{
	int	*tab;

	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	storage_value(a, tab);
	quick_sort_array(tab, 0, size - 1);
	binary_search(a, size, tab);
	// // confirm tab
	// t_node	*head;
	// head = a;
	// a = a->next;
	// while (a != head)
	// {
	// 	printf("a[%lu]:%d\n", a->index, a->val);
	// 	a = a->next;
	// }

	free(tab);
}
