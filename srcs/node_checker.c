/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:58 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/11 00:46:58 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	node_dup_check(t_node *a)
{
	t_node	*head;
	t_node	*tmp;

	head = a;
	a = a->next;
	while (a != head)
	{
		tmp = a->next;
		while (tmp != head)
		{
			if (a->val == tmp->val)
			{
				write(2, "Error\n", 6);
				free_all_node(head);
				exit(EXIT_FAILURE);
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
}

static size_t	node_size_check(t_node *a)
{
	size_t	size;
	t_node	*head;

	size = 0;
	head = a;
	a = a->next;
	while (a != head)
	{
		size++;
		a = a->next;
	}
	return (size);
}

static void	node_sorted_check(t_node *a, size_t size, int b_flag)
{
	size_t	i;
	t_node	*head;

	i = 0;
	head = a;
	a = a->next;
	while (a != head)
	{
		if (a->next != head)
			if (a->val < a->next->val)
				i++;
		a = a->next;
	}
	if (i + 1 == size)
	{
		free_all_node(head);
		if (b_flag)
			write(1, "OK\n", 3);
		exit(EXIT_SUCCESS);
	}
}

size_t	node_check(t_node *a, int b_flag)
{
	size_t	size;

	size = 0;
	node_dup_check(a);
	size = node_size_check(a);
	node_sorted_check(a, size, b_flag);
	return (size);
}
