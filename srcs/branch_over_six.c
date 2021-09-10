/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_over_six.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:18 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/11 00:46:18 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	double_node_free(t_node *a, t_node *b)
{
	free_all_node(a);
	free_all_node(b);
	write(1, "Error\n", 6);
}

void	size_over_six(t_node *a, t_node *b, size_t size)
{
	compression_main(a, size);
	a_to_b(a, b, size);
	return ;
}
