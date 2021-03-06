/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:47:05 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/16 17:39:15 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include <stdio.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define RA 0
# define RB 1
# define RRA 2
# define RRB 3
# define SA 4
# define SB 5
# define PA 6
# define PB 7
# define SS 8
# define RR 9
# define RRR 10

typedef struct s_node
{
	int				val;
	size_t			index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_ps
{
	size_t	ra;
	size_t	rb;
	size_t	pa;
	size_t	pb;
	int		ra_flag;
	int		rb_flag;
	int		atob_flag;
	size_t	origin;
	int		pivot_big;
	int		pivot_small;
}	t_ps;

typedef struct s_cmd
{
	int				val;
	struct s_cmd	*prev;
	struct s_cmd	*next;
}	t_cmd;

// main.c
void	argument_check(int args, char *argv[]);
void	branch_node_size(t_node *a, t_node *b, size_t size);

// utils.c
int		ft_isdigit_str(char *str);
int		ft_integer_check(char *str);

// node.c
t_node	*head_node(void);
void	init_node(t_node *a, int args, char *argv[]);
void	free_all_node(t_node *node);

// node_checker.c
size_t	node_check(t_node *a, int b_flag, int c_flag);

// branch.c
void	size_two(t_node *a);
void	size_three_case(t_node *a, int x, int y, int z);
void	size_three(t_node *a);

// branch_until_six.c
size_t	min_search(t_node *a);
size_t	max_search(t_node *a);
void	size_until_six(t_node *a, t_node *b, size_t size);

// action_main.c
void	swap(t_node *node, int ab_flag, int same_flag);
void	rotate(t_node *node, int ab_flag, int same_flag);
void	reverse_rotate(t_node *node, int ab_flag, int same_flag);
void	push(t_node *n1, t_node *n2, int atob_flag);
void	both_action(t_node *a, t_node *b, int flag);

// compression_1.c
void	compression_main(t_node *a, size_t size);
void	quick_sort_array(int tab[], size_t l, size_t r);
void	storage_value(t_node *a, int *tab, size_t size);

// compression_2.c
void	binary_search(t_node *a, size_t size, int *tab);
void	init_count(t_ps *count, size_t size);
void	size_pivot_double(t_node *a, size_t size, t_ps *count);

// branch_over_six.c
void	size_over_six(t_node *a, t_node *b, size_t size);
int		sort_check_a(t_node *a, size_t size);
int		sort_check_b(t_node *b, size_t size);
size_t	node_size(t_node *a);
void	double_node_free(t_node *a, t_node *b);

// quick_sort_stack.c
void	a_to_b(t_node *a, t_node *b, size_t size);
void	b_to_a(t_node *a, t_node *b, size_t size);

// sort_utils.c
void	size_two_atobtoa(t_node *a, t_node *b, size_t size, int flag);
int		above_two_check_a(t_node *a, size_t size, t_node *head);

// NEO ZONE
// neo_branch_over_six.c

// neo_quick_sort_stack.c
void	a_to_b_neo(t_node *a, t_node *b, size_t size, t_cmd **lst);
void	b_to_a_neo(t_node *a, t_node *b, size_t size, t_cmd **lst);

// neo_sort_utils.c
void	size_two_btoa_neo(t_node *a, t_node *b, size_t size, t_cmd **lst);
void	size_two_atob_neo(t_node *a, t_node *b, size_t size, t_cmd **lst);
size_t	min_index_search(t_node *a, size_t size);

// neo_action.c
void	swap_neo(t_node *node, t_node *sub, int cmd, t_cmd **lst);
void	rotate_neo(t_node *node, t_node *sub, int cmd, t_cmd **lst);
void	reverse_rotate_neo(t_node *node, t_node *sub, int cmd, t_cmd **lst);
void	push_neo(t_node *n1, t_node *n2, int cmd, t_cmd **lst);
void	both_action_neo(t_node *a, t_node *b, int cmd, t_cmd **lst);

// neo_cmd_list.c
int		lstadd_back(t_cmd **lst, int cmd);
void	lstclear(t_cmd **lst);

// neo_cmd_edit.c
void	edit_cmd(t_cmd *lst);

// visualize.c
void	visualize_node(t_node *a, t_node *b);

#endif
