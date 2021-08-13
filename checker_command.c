#include "checker.h"

void	cmd_stack(t_node *a, t_node *b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa\n", 3))
		swap_c(a);
	else if (!ft_strncmp(cmd, "sb\n", 3))
		swap_c(b);
	else if (!ft_strncmp(cmd, "ra\n", 3))
		rotate_c(a);
	else if (!ft_strncmp(cmd, "rb\n", 3))
		rotate_c(b);
	else if (!ft_strncmp(cmd, "rra\n", 4))
		reverse_rotate_c(a);
	else if (!ft_strncmp(cmd, "rrb\n", 4))
		reverse_rotate_c(b);
	else if (!ft_strncmp(cmd, "pa\n", 3))
		push_c(b, a);
	else if (!ft_strncmp(cmd, "pb\n", 3))
		push_c(a, b);
}

void	cmd_sort_check(t_node *a, t_node *b)
{
	t_node	*head;
	size_t	size;
	size_t	sort;
	size_t	i;

	head = a;
	size = node_size(a);
	i = 0;
	sort = 0;
	a = a->next;
	while (i < size)
	{
		if (a->next != head)
			if (a->val < a->next->val)
				sort++;
		i++;
	}
	if (i != sort || node_size(b))
	{
		write(1, "KO\n", 3);
		// exit(EXIT_SUCCESS);
	}
	write(1, "OK\n", 3);
	// exit(EXIT_SUCCESS);
}
