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
// void	delete_node_error(t_node *node);

// node_checker.c
size_t	node_check(t_node *a);

#endif
