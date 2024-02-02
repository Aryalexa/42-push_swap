#include "push_swap.h"

void	rra(t_game **game)
{
	t_stack	*st;

	st = (*game)->stack_a;
	if (op_reverse_rotate(&st))
		add_to_sol(game, "rra");
}

void	rrb(t_game **game)
{
	t_stack	*st;

	st = (*game)->stack_b;
	if (op_reverse_rotate(&st))
		add_to_sol(game, "rrb");
}

void	rrr(t_game **game)
{
	t_stack	*a;
	t_stack	*b;

	a = (*game)->stack_a;
	b = (*game)->stack_b;
	if (a->size < 2 || b->size < 2)
		return ;
	op_reverse_rotate(&a);
	op_reverse_rotate(&b);
	add_to_sol(game, "rrr");
}
