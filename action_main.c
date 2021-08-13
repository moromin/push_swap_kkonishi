#include "ps.h"

void	swap(t_node *node, int ab_flag, int same_flag)
{
	t_node	*head;
	t_node	*node1;
	t_node	*node2;

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