#include "ps.h"

void	swap_neo(t_node *node, t_node *sub, int cmd, t_cmd **lst)
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
	if (cmd < 8)
		if (lstadd_back(lst, cmd) < 0)
			double_node_free(node, sub);
}

void	rotate_neo(t_node *node, t_node *sub, int cmd, t_cmd **lst)
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
	if (cmd < 8)
		if (lstadd_back(lst, cmd) < 0)
			double_node_free(node, sub);
}

void	reverse_rotate_neo(t_node *node, t_node *sub, int cmd, t_cmd **lst)
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
	if (cmd < 8)
		if (lstadd_back(lst, cmd) < 0)
			double_node_free(node, sub);
}

void	push_neo(t_node *n1, t_node *n2, int cmd, t_cmd **lst)
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
	if (cmd < 8)
		if (lstadd_back(lst, cmd) < 0)
			double_node_free(n1, n2);
}

void	both_action_neo(t_node *a, t_node *b, int cmd, t_cmd **lst)
{
	if (cmd == SS)
	{
		swap_neo(a, b, cmd, lst);
		swap_neo(b, a, cmd, lst);
	}
	else if (cmd == RR)
	{
		rotate_neo(a, b, cmd, lst);
		rotate_neo(b, a, cmd, lst);
	}
	else if (cmd == RRR)
	{
		reverse_rotate_neo(a, b, cmd, lst);
		reverse_rotate_neo(b, a, cmd, lst);
	}
	if (lstadd_back(lst, cmd) < 0)
		double_node_free(a, b);
}
