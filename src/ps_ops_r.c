/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_r.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastro <macastro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:18:20 by macastro          #+#    #+#             */
/*   Updated: 2024/04/11 19:18:21 by macastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_game **game)
{
	t_stack	*st;

	st = (*game)->stack_a;
	if (op_rotate(&st))
		add_to_sol(game, "ra");
}

void	rb(t_game **game)
{
	t_stack	*st;

	st = (*game)->stack_b;
	if (op_rotate(&st))
		add_to_sol(game, "rb");
}

void	rr(t_game **game)
{
	t_stack	*a;
	t_stack	*b;

	a = (*game)->stack_a;
	b = (*game)->stack_b;
	if (a->size < 2 || b->size < 2)
		return ;
	op_rotate(&a);
	op_rotate(&b);
	add_to_sol(game, "rr");
}
