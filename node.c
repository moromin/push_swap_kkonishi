#include "ps.h"

t_node	*head_node(void)
{
	t_node	*head;

	head = (t_node *)malloc(sizeof(t_node));
	if (!head)
	{
		write(1, "Error\n", 6);
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
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
	new->val = val;
	head->prev->next = new;
	new->prev = head->prev;
	new->next = head;
	head->prev = new;
}

void	init_node(t_node *a, int args, char *argv[])
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < args)
	{
		j = 0;
		while (argv[i][j])
		{
			add_node(a, ft_atoi(&argv[i][j]));
			while ((ft_isdigit(argv[i][j]) || argv[i][j] == '-') && argv[i][j])
				j++;
			while (!(ft_isdigit(argv[i][j]) || argv[i][j] == '-') && argv[i][j])
				j++;
		}
		i++;
	}
}

// TODO
// Delete all node when malloc is fail
// void	delete_node_error(t_node *node)
// {

// }