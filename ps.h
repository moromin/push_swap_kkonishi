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
	size_t			index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_ps
{
	size_t	pb;
	size_t	rb;
}	t_ps;

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
size_t	min_search(t_node *a);
size_t	max_search(t_node *a);
void	size_until_six(t_node *a, t_node *b, size_t size);

// branch_over_six.c
void	size_over_six(t_node *a, t_node *b, size_t size);

// action_main.c
void	swap(t_node *node, int ab_flag, int same_flag);
void	rotate(t_node *node, int ab_flag, int same_flag);
void	reverse_rotate(t_node *node, int ab_flag, int same_flag);
void	push(t_node *n1, t_node *n2, int atob_flag);

// action_sub.c
void	ss(t_node *a, t_node *b);
void	rr(t_node *a, t_node *b);
void	rrr(t_node *a, t_node *b);

// compression_1.c
void	compression_main(t_node *a, size_t size);
void	quick_sort_array(int tab[], size_t l, size_t r);
void	storage_value(t_node *a, int *tab, size_t size);

// compression_2.c
void	binary_search(t_node *a, size_t size, int *tab);

// quick_sort_stack.c
void	sort_stack(t_node *a, t_node *b, size_t size);
int		sort_check_a(t_node *a, size_t size);
int		sort_check_b(t_node *b, size_t size);
size_t	node_size(t_node *a);
void	push_btoa(t_node *a, t_node *b, size_t size);
void	a_to_b(t_node *a, t_node *b, size_t size);
void	b_to_a(t_node *a, t_node *b, size_t size);

#endif
