#include "ps.h"

void	ss(t_node *a, t_node *b)
{
	swap(a, 0, 1);
	swap(b, 0, 1);
	write(1, "ss\n", 3);
}

void	rr(t_node *a, t_node *b)
{
	rotate(a, 0, 1);
	rotate(b, 0, 1);
	write(1, "rr\n", 3);
}

void	rrr(t_node *a, t_node *b)
{
	reverse_rotate(a, 0, 1);
	reverse_rotate(b, 0, 1);
	write(1, "rrr\n", 4);
}
