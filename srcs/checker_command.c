/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_command.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:30 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/16 17:46:58 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	no_exit_action(t_node *a, t_node *b, char *cmd)
{
	ft_putendl_fd("Error", 2);
	free_all_node(a);
	free_all_node(b);
	free(cmd);
	exit(EXIT_FAILURE);
}

void	cmd_stack(t_node *a, t_node *b, char *cmd)
{
	if (!ft_strcmp(cmd, "sa\n"))
		swap_c(a);
	else if (!ft_strcmp(cmd, "sb\n"))
		swap_c(b);
	else if (!ft_strcmp(cmd, "ra\n"))
		rotate_c(a);
	else if (!ft_strcmp(cmd, "rb\n"))
		rotate_c(b);
	else if (!ft_strcmp(cmd, "rra\n"))
		reverse_rotate_c(a);
	else if (!ft_strcmp(cmd, "rrb\n"))
		reverse_rotate_c(b);
	else if (!ft_strcmp(cmd, "pa\n"))
		push_c(b, a);
	else if (!ft_strcmp(cmd, "pb\n"))
		push_c(a, b);
	else if (!ft_strcmp(cmd, "ss\n"))
		both_action_c(a, b, SS);
	else if (!ft_strcmp(cmd, "rr\n"))
		both_action_c(a, b, RR);
	else if (!ft_strcmp(cmd, "rrr\n"))
		both_action_c(a, b, RRR);
	else
		no_exit_action(a, b, cmd);
}

void	not_sorted_stack(t_node *a, t_node *b)
{
	ft_putendl_fd("KO", 1);
	free_all_node(a);
	free_all_node(b);
	exit(EXIT_SUCCESS);
}

void	cmd_sort_check(t_node *a, t_node *b)
{
	t_node	*head;
	size_t	size;
	size_t	i;

	head = a;
	size = node_size(a);
	i = 0;
	a = a->next;
	while (i < size)
	{
		if (a->next != head)
			if (a->val > a->next->val)
				not_sorted_stack(a, b);
		i++;
		a = a->next;
	}
	if (node_size(b))
		ft_putendl_fd("KO", 1);
	else
		ft_putendl_fd("OK", 1);
	free_all_node(a);
	free_all_node(b);
	exit(EXIT_SUCCESS);
}
