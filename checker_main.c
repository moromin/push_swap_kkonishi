#include "checker.h"

void	argument_check(int args, char *argv[])
{
	size_t	i;

	if (args < 2)
		exit(EXIT_FAILURE);
	i = 1;
	while (i < (size_t)args)
	{
		if (ft_isdigit_str(argv[i]))
			exit(EXIT_FAILURE);
		if (ft_integer_check(argv[i]))
			exit(EXIT_FAILURE);
		i++;
	}
}

void	branch_node_size(t_node *a, t_node *b, size_t size)
{
	if (size == 2)
		size_two(a);
	else if (size == 3)
		size_three(a);
	else if (size <= 6)
		size_until_six(a, b, size);
	else
		size_over_six(a, b, size);
}

int	main(int args, char *argv[])
{
	t_node	*a;
	t_node	*b;
	size_t	size;
	char	*cmd;

	cmd = get_next_line(0);
	if (!cmd)
		exit(EXIT_FAILURE);
	a = head_node();
	argument_check(args, argv);
	init_node(a, args, argv);
	size = node_check(a);
	b = head_node();
	while (cmd != NULL)
	{
		cmd_stack(a, b, cmd);
		free(cmd);
		cmd = get_next_line(0);
	}
	cmd_sort_check(a, b);
	// confirm
	t_node	*head_a = a;
	t_node	*head_b = b;
	int		i = 0;
	
	a = a->next;
	while (a != head_a)
	{
		printf("a[%d]:%d\n", i, a->val);
		a = a->next;
		i++;
	}
	i = 0;
	b = b->next;
	while (b != head_b)
	{
		printf("b[%d]:%d\n", i, b->val);
		b = b->next;
		i++;
	}
	return (0);
}
