#include "ps.h"

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

	a = head_node();
	argument_check(args, argv);
	init_node(a, args, argv);
	size = node_check(a);
	b = head_node();
	branch_node_size(a, b, size);
	return (0);
}
	// To confirm node
	// t_node	*head_a;
	// t_node	*head_b;
	// int		i;

	// head_a = a;
	// head_b = b;
	// i = 0;
	// a = a->next;
	// printf("-------\n");
	// while (a != head_a)
	// {
	// 	i++;
	// 	printf("a%d:%d\n", i, a->val);
	// 	a = a->next;
	// }
	// i = 0;
	// b = b->next;
	// printf("-------\n");
	// while (b != head_b)
	// {
	// 	i++;
	// 	printf("b%d:%d\n", i, b->val);
	// 	b = b->next;
	// }
	// printf("-------\n");

	// leaks check
	// free_all_node(a);
	// free_all_node(b);
	// system("leaks push_swap");
