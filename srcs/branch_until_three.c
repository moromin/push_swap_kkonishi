/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   branch_until_three.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:23 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/11 00:46:24 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ps.h"

void	size_two(t_node *a)
{
	swap(a, 1, 0);
}

void	size_three_case(t_node *a, int x, int y, int z)
{
	if (x > y && y < z && z > x)
		swap(a, 1, 0);
	else if (x > y && y > z && z < x)
	{
		swap(a, 1, 0);
		reverse_rotate(a, 1, 0);
	}
	else if (x > y && y < z && z < x)
		rotate(a, 1, 0);
	else if (x < y && y > z && z > x)
	{
		swap(a, 1, 0);
		rotate(a, 1, 0);
	}
	else if (x < y && y > z && z < x)
		reverse_rotate(a, 1, 0);
}

void	size_three(t_node *a)
{
	int	x;
	int	y;
	int	z;

	x = a->next->val;
	y = a->next->next->val;
	z = a->next->next->next->val;
	size_three_case(a, x, y, z);
}
