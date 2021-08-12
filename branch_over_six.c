#include "ps.h"

void	size_over_six(t_node *a, t_node *b, size_t size)
{
	(void)b;
	compression_main(a, size);
	half_set(a, b, size);
	return ;
}
