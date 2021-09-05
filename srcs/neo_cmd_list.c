#include "ps.h"

t_cmd	*lstnew(int cmd)
{
	t_cmd	*lst;

	lst = (t_cmd *)malloc(sizeof(t_cmd));
	if (lst == NULL)
		return (NULL);
	lst->val = cmd;
	lst->next = NULL;
	lst->prev = NULL;
	return (lst);
}

t_cmd	*lstlast(t_cmd *lst)
{
	t_cmd	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	if (lst)
		while (tmp->next != NULL)
			tmp = tmp->next;
	return (tmp);
}

void	lstclear(t_cmd **lst)
{
	t_cmd	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

int	lstadd_back(t_cmd **lst, int cmd)
{
	t_cmd	*tmp;
	t_cmd	*new;

	if (!lst)
		return (-1);
	new = lstnew(cmd);
	if (!new)
	{
		lstclear(lst);
		return (-1);
	}
	if (!*lst)
	{
		*lst = new;
		return (0);
	}
	tmp = lstlast(*lst);
	tmp->next = new;
	new->prev = tmp;
	return (0);
}
