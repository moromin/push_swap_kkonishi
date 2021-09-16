/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:33 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/16 17:42:08 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
	char	*cmd;

	a = head_node();
	argument_check(args, argv);
	init_node(a, args, argv);
	node_check(a, 1, 1);
	b = head_node();
	while (1)
	{
		cmd = get_next_line(0);
		if (cmd == NULL)
			break ;
		cmd_stack(a, b, cmd);
		free(cmd);
	}
	cmd_sort_check(a, b);
	return (0);
}
