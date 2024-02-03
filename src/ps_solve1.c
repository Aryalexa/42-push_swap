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
 * Return the number of case.
 * case 0: [1,2,3] => [m,2,M]
 * case 1: [2,3,1] => [2,M,m]
 * case 2: [3,1,2] => [M,m,2]
 * case 3: [3,2,1] => [M,2,m]
 * case 4: [2,1,3] => [2,m,M]
 * case 5: [1,3,2] => [m,M,2]
 * case -1: error
*/
static t_3case	discern_3elem_case(int n1, int n2, int n3)
{
	int	min;
	int	max;

	min = ft_min_nbr(ft_min_nbr(n1, n2), n3);
	max = ft_max_nbr(ft_max_nbr(n1, n2), n3);
	if (n1 == min && n3 == max)
		return (PS_123);
	if (n3 == min && n2 == max)
		return (PS_231);
	if (n2 == min && n1 == max)
		return (PS_312);
	if (n3 == min && n1 == max)
		return (PS_321);
	if (n2 == min && n3 == max)
		return (PS_213);
	if (n1 == min && n2 == max)
		return (PS_132);
	return (PS_ERR);
}

/**
 * Solve the 3-element stack using the cases:
 * 
 * 0:[1,2,3] -> ok
 * 1:[2,3,1] -> rra -> [1,2,3] -> ok
 * 2:[3,1,2] -> ra  -> [1,2,3] -> ok
 * 3:[3,2,1] -> sa  -> [2,3,1] -> rra -> [1,2,3] -> ok
 * 4:[2,1,3] -> sa  -> [1,2,3] -> ok
 * 5:[1,3,2] -> rra -> [2,1,3] -> sa  -> [1,2,3] -> ok
*/
static void	solve_small_ps_3(t_game **game, int v_3e_case)
{
	if (v_3e_case == PS_231)
		rra(game);
	else if (v_3e_case == PS_312)
		ra(game);
	else if (v_3e_case == PS_321)
	{
		sa(game);
		rra(game);
	}
	else if (v_3e_case == PS_213)
		sa(game);
	else if (v_3e_case == PS_132)
	{
		rra(game);
		sa(game);
	}
}

/**
 * Solve stack A when there's 3 elements or less
*/
void	solve_small_ps(t_game **game)
{
	t_3case	v_3e_case;

	if (is_sorted((*game)->stack_a) || (*game)->stack_a->size <= 1)
		return ;
	if ((*game)->stack_a->size == 2)
	{
		sa(game);
		return ;
	}
	v_3e_case = discern_3elem_case(
			(*game)->stack_a->head->num,
			(*game)->stack_a->head->next->num,
			(*game)->stack_a->head->next->next->num
			);
	if (v_3e_case == PS_ERR)
		return ;
	solve_small_ps_3(game, v_3e_case);
}
