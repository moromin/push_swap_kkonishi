#ifndef PS_H
# define PS_H

# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				val;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

// main.c
void	argument_check(int args, char *argv[]);

// utils.c
int		ft_isdigit_str(char *str);
int		ft_integer_check(char *str);

// node.c
t_node	*head_node(void);
void	init_node(t_node *a, int args, char *argv[]);
void	free_all_node(t_node *node);

// node_checker.c
size_t	node_check(t_node *a);

// branch.c
void	size_two(t_node *a);
void	size_three_case(t_node *a, int x, int y, int z);
void	size_three(t_node *a);

// branch_until_six.c
void	size_until_six(t_node *a, t_node *b, size_t size);

// branch_over_six.c
void	size_over_six(t_node *a, t_node *b);

// action_main.c
void	swap(t_node *node, int ab_flag, int same_flag);
void	rotate(t_node *node, int ab_flag, int same_flag);
void	reverse_rotate(t_node *node, int ab_flag, int same_flag);
void	push(t_node *n1, t_node *n2, int atob_flag);

// action_sub.c
void	ss(t_node *a, t_node *b);
void	rr(t_node *a, t_node *b);
void	rrr(t_node *a, t_node *b);

#endif
