#include "ps.h"

static int	argv_empty_check(char *str)
{
	int		flag;
	size_t	i;

	flag = 0;
	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || str[i] == ' ' || str[i] == '-')
			flag++;
		i++;
	}
	if (!flag)
		return (write(2, "Error\n", 6));
	return (0);
}

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
		if (argv_empty_check(argv[i]))
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
	free_all_node(a);
	free_all_node(b);
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
