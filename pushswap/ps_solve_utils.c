#include "push_swap.h"

t_bool	is_sorted(t_stack *st)
{
	t_intnode	*cur;
	t_intnode	*next;
	t_order		order;

	order = st->order;
	cur = st->head;
	while (cur->next)
	{
		next = cur->next;
		if (order == ASC && cur->num > next->num)
			return (FALSE);
		if (order == DESC && cur->num < next->num)
			return (FALSE);
		cur = next;
	}
	return (TRUE);
}

/**
 * The function assumes at least one element in st_src.
 * load `play`: the min-cost play case to apply:
 * returns the cheapest number to move
*/
static int	cheapest_number(t_stack *st_src, t_stack *st_dst, t_play *play)
{
	int			cheapest;
	int			moves;
	int			cur_moves;
	t_intnode	*cur;
	t_play		cur_play;

	cur = st_src->head;
	moves = st_src->size * 100;
	while (cur)
	{
		cur_moves = cheapest_play(st_src, st_dst, cur->num, &cur_play);
		if (cur_moves < moves)
		{
			moves = cur_moves;
			*play = cur_play;
			cheapest = cur->num;
		}
		cur = cur->next;
	}
	return (cheapest);
}


/**
 * Move elements from stack_A to stack_B.
 * Move first two elements and keep stack_B sorted in circular descending order.
 * Keep moving until there's only 3 elements in stack_A.
*/
static void	move_2b(t_game **game)
{
	int			num;
	t_play		play;

	if ((*game)->stack_a->size > 3 && !is_sorted((*game)->stack_a))
		pb(game);
	if ((*game)->stack_a->size > 3 && !is_sorted((*game)->stack_a))
		pb(game);
	while ((*game)->stack_a->size > 3 && !is_sorted((*game)->stack_a))
	{
		num = cheapest_number((*game)->stack_a, (*game)->stack_b, &play);
		apply_play_moves(game, A2B, num, play);
	}
}

/**
 * Sort what's left in stack_A and start moving back the elements from stack_B
 * Keep stack_A sorted in circular ascending order.
 * Keep moving until stack_B is empty.
*/
static void	moveback_2a(t_game **game)
{
	int			num;
	t_play		play;

	if ((*game)->stack_a->size <= 3 && !is_sorted((*game)->stack_a))
		solve_small_ps(game);
	while ((*game)->stack_b->size > 0)
	{
		num = cheapest_number((*game)->stack_b, (*game)->stack_a, &play);
		apply_play_moves(game, B2A, num, play);
	}
}

void	solve_big_ps(t_game **game)
{
	ft_printf("BIG!\n");
	ft_printf("-----move_2B INIT\n");
	move_2b(game);
	ft_printf("move_2B FIN\n");
	ft_printf("-----move_2A INIT\n");
	moveback_2a(game);
	ft_printf("move_2A FIN\n");

	//arrange_min_first(game);
}
