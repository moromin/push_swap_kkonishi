#include "ps.h"

void	argument_check(int args, char *argv[])
{
	size_t	i;

	if (args < 2)
		exit(EXIT_FAILURE);
	i = 1;
	while (i < args)
	{
		if (ft_isdigit_str(argv[i]))
			exit(EXIT_FAILURE);
		if (ft_integer_check(argv[i]))
			exit(EXIT_FAILURE);
		// if (ft_duplicate_check(argv[i]))
		// 	exit(EXIT_FAILURE);
		i++;
	}
}

int	main(int args, char *argv[])
{
	t_node	*a;
	t_node	*b;
	size_t	size;

	a = head_node();
	b = head_node();
	argument_check(args, argv);
	init_node(a, args, argv);
	size = node_check(a);

	// To confirm node
	t_node	*tmp;
	int		i;

	tmp = a;
	i = 0;
	a = a->next;
	while (a != tmp)
	{
		i++;
		printf("val%d:%d\n", i, a->val);
		a = a->next;
	}
	printf("node_size:%lu\n", size);
	// TODO
	// node size check to sort
	// int	flag;
	// flag = node_size();

	// while (i < args)
	// {
	// 	printf("'%s'\n", argv[i++]);
	// }
}
