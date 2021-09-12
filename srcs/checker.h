/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkonishi <kkonishi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/11 00:46:35 by kkonishi          #+#    #+#             */
/*   Updated: 2021/09/11 00:46:36 by kkonishi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "ps.h"
# include "../gnl/get_next_line_bonus.h"

// checker_command.c
void	cmd_stack(t_node *a, t_node *b, char *cmd);
void	cmd_sort_check(t_node *a, t_node *b);

// checker_action.c
void	swap_c(t_node *node);
void	rotate_c(t_node *node);
void	reverse_rotate_c(t_node *node);
void	push_c(t_node *n1, t_node *n2);
void	both_action_c(t_node *a, t_node *b, int flag);

#endif
