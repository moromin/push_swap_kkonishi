/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compression_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:38 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/11 00:46:38 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	quick_sort_array(int tab[], size_t l, size_t r)
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

void	storage_value(t_node *a, int *tab, size_t size)
{
	size_t	i;

	i = 0;
	a = a->next;
	while (i < size)
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
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	storage_value(a, tab, size);
	quick_sort_array(tab, 0, size - 1);
	binary_search(a, size, tab);
	free(tab);
}
