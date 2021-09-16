/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_main.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:11 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/16 17:21:34 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	swap(t_node *node, int ab_flag, int same_flag)
{
	t_node	*head;
	t_node	*node1;
	t_node	*node2;

	if (node_size(node) < 2)
		return ;
	head = node;
	node1 = head->next;
	node2 = head->next->next;
	node1->prev->next = node2;
	node2->next->prev = node1;
	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;
	if (!same_flag)
	{
		if (ab_flag)
			write(1, "sa\n", 3);
		else
			write(1, "sb\n", 3);
	}
}

void	rotate(t_node *node, int ab_flag, int same_flag)
{
	t_node	*head;
	t_node	*node1;
	t_node	*node2;

	head = node;
	node1 = head->next;
	node2 = head->prev;
	if (node1->next == head)
		return ;
	head->next = node1->next;
	node1->next->prev = head;
	node1->next = head;
	node1->prev = node2;
	head->prev = node1;
	node2->next = node1;
	if (!same_flag)
	{
		if (ab_flag)
			write(1, "ra\n", 3);
		else
			write(1, "rb\n", 3);
	}
}

void	reverse_rotate(t_node *node, int ab_flag, int same_flag)
{
	t_node	*head;
	t_node	*node1;
	t_node	*node2;

	head = node;
	node1 = head->next;
	node2 = head->prev;
	if (node1->next == head)
		return ;
	head->prev = node2->prev;
	node2->prev->next = head;
	node2->next = node1;
	node2->prev = head;
	head->next = node2;
	node1->prev = node2;
	if (!same_flag)
	{
		if (ab_flag)
			write(1, "rra\n", 4);
		else
			write(1, "rrb\n", 4);
	}
}

void	push(t_node *n1, t_node *n2, int atob_flag)
{
	t_node	*head_n1;
	t_node	*head_n2;
	t_node	*node1;
	t_node	*node2;

	if (node_size(n1) == 0)
		return ;
	head_n1 = n1;
	node1 = head_n1->next;
	node1->next->prev = head_n1;
	head_n1->next = node1->next;
	head_n2 = n2;
	node2 = head_n2->next;
	node1->next = node2;
	node1->prev = head_n2;
	head_n2->next = node1;
	node2->prev = node1;
	if (atob_flag)
		write(1, "pb\n", 3);
	else
		write(1, "pa\n", 3);
}

void	both_action(t_node *a, t_node *b, int flag)
{
	if (flag == SS)
	{
		swap(a, 0, 1);
		swap(b, 0, 1);
		write(1, "ss\n", 3);
	}
	else if (flag == RR)
	{
		rotate(a, 0, 1);
		rotate(b, 0, 1);
		write(1, "rr\n", 3);
	}
	else if (flag == RRR)
	{
		reverse_rotate(a, 0, 1);
		reverse_rotate(b, 0, 1);
		write(1, "rrr\n", 4);
	}
}
