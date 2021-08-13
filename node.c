#include "ps.h"

t_node	*head_node(void)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (!head)
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	head->next = head;
	head->prev = head;
	return (head);
}

static void	add_node(t_node *head, int val)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
	{
		write(2, "Error\n", 6);
		free_all_node(head);
		exit(EXIT_FAILURE);
	}
	new->val = val;
	head->prev->next = new;
	new->prev = head->prev;
	new->next = head;
	head->prev = new;
}

static int	argv_check(char c)
{
	return (ft_isdigit(c) || c == '-');
}

void	init_node(t_node *a, int args, char *argv[])
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < (size_t)args)
	{
		j = 0;
		while (argv[i][j])
		{
			add_node(a, ft_atoi(&argv[i][j]));
			while (!argv_check(argv[i][j]) && argv[i][j])
				j++;
			while (argv_check(argv[i][j]) && argv[i][j])
				j++;
		}
		i++;
	}
}

void	free_all_node(t_node *node)
{
	t_node	*head;
	t_node	*tmp;

	head = node;
	node = node->next;
	while (node != head)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	free(head);
}
