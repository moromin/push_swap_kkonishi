/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neo_branch_over_six.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:45 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/11 00:46:46 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

size_t	node_size(t_node *a)
{
	t_node	*head;
	size_t	size;

	head = a;
	size = 0;
	a = a->next;
	while (a != head)
	{
		size++;
		a = a->next;
	}
	return (size);
}

int	sort_check_a(t_node *a, size_t size)
{
	t_node	*head;
	size_t	sort;
	size_t	i;

	head = a;
	sort = 0;
	i = 0;
	a = a->next;
	while (i < size - 1)
	{
		if (a->next != head)
			if (a->val < a->next->val)
				sort++;
		a = a->next;
		i++;
	}
	if (sort == i)
		return (1);
	else
		return (0);
}

void	visualize_cmd(t_cmd *lst)
{
	while (lst)
	{
		if (lst->val == RA)
			printf("ra");
		if (lst->val == RB)
			printf("rb");
		if (lst->val == RRA)
			printf("rra");
		if (lst->val == RRB)
			printf("rrb");
		if (lst->val == SA)
			printf("sa");
		if (lst->val == SB)
			printf("sb");
		if (lst->val == PA)
			printf("pa");
		if (lst->val == PB)
			printf("pb");
		if (lst->val == RR)
			printf("rr");
		if (lst->val == RRR)
			printf("rrr");
		printf("\n");
		lst = lst->next;
	}
}

void	double_node_free(t_node *a, t_node *b)
{
	free_all_node(a);
	free_all_node(b);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	size_over_six(t_node *a, t_node *b, size_t size)
{
	t_cmd	*lst;

	lst = NULL;
	compression_main(a, size);
	a_to_b_neo(a, b, size, &lst);
	edit_cmd(lst);
	visualize_cmd(lst);
	lstclear(&lst);
	return ;
}
