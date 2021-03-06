/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_action.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:27 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/16 17:20:26 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	swap_c(t_node *node)
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
}

void	rotate_c(t_node *node)
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
}

void	reverse_rotate_c(t_node *node)
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
}

void	push_c(t_node *n1, t_node *n2)
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
}

void	both_action_c(t_node *a, t_node *b, int flag)
{
	if (flag == SS)
	{
		swap_c(a);
		swap_c(b);
	}
	else if (flag == RR)
	{
		rotate_c(a);
		rotate_c(b);
	}
	else if (flag == RRR)
	{
		reverse_rotate_c(a);
		reverse_rotate_c(b);
	}
}
