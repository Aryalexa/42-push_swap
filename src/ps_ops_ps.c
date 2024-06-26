/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_ps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastro <macastro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:18:16 by macastro          #+#    #+#             */
/*   Updated: 2024/04/11 19:18:17 by macastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_game **game)
{
	t_stack	*st;

	st = (*game)->stack_a;
	if (op_swap(&st))
		add_to_sol(game, "sa");
}

void	sb(t_game **game)
{
	t_stack	*st;

	st = (*game)->stack_b;
	if (op_swap(&st))
		add_to_sol(game, "sb");
}

void	ss(t_game **game)
{
	t_stack	*a;
	t_stack	*b;

	a = (*game)->stack_a;
	b = (*game)->stack_b;
	if (a->size < 1 || b->size < 1)
		return ;
	op_swap(&a);
	op_swap(&b);
	add_to_sol(game, "ss");
}

void	pa(t_game **game)
{
	t_stack	*a;
	t_stack	*b;

	a = (*game)->stack_a;
	b = (*game)->stack_b;
	if (op_push(&a, &b))
		add_to_sol(game, "pa");
}

void	pb(t_game **game)
{
	t_stack	*a;
	t_stack	*b;

	a = (*game)->stack_a;
	b = (*game)->stack_b;
	if (op_push(&b, &a))
		add_to_sol(game, "pb");
}
