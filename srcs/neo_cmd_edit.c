/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   neo_cmd_edit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:48 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/11 00:46:48 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

static void	ra_rb_to_rr(t_cmd *lst)
{
	t_cmd	*head;
	t_cmd	*next;

	head = lst;
	next = lst->next;
	if (head->val == RA && next->val == RB)
	{
		head->val = RR;
		head->next = next->next;
		if (next->next)
			next->next->prev = head;
		free(next);
	}
	else if (head->val == RB && next->val == RA)
	{
		head->val = RR;
		head->next = next->next;
		if (next->next)
			next->next->prev = head;
		free(next);
	}
}

static t_cmd	*delete_double_cmd(t_cmd *head, t_cmd *lst)
{
	t_cmd	*tmp;

	tmp = lst->next;
	head->prev->next = head->next;
	head->next->prev = head->prev;
	lst->next->prev = lst->prev;
	lst->prev->next = lst->next;
	free(head);
	free(lst);
	head = NULL;
	lst = NULL;
	return (tmp);
}

static t_cmd	*ra_rra_delete(t_cmd *lst, int cmd)
{
	t_cmd	*head;

	head = lst;
	lst = lst->next;
	while (lst)
	{
		if (lst->val == RRA && cmd == RA)
			return (delete_double_cmd(head, lst));
		if (lst->val == RRB && cmd == RB)
			return (delete_double_cmd(head, lst));
		if (!(lst->val == RRA || lst->val == RRB || lst->val == RRR))
			return (head);
		lst = lst->next;
	}
	return (head);
}

void	edit_cmd(t_cmd *lst)
{
	t_cmd	*head;
	t_cmd	*tmp;
	size_t	i;

	i = 1;
	head = lst;
	while (lst)
	{
		tmp = lst->next;
		if ((lst->val == RB || lst->val == RA) && tmp)
			ra_rb_to_rr(lst);
		if (lst->val == RB || lst->val == RA)
			lst = ra_rra_delete(lst, lst->val);
		if (lst)
			lst = lst->next;
		i++;
	}
}
