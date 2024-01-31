#include "push_swap.h"


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
static int	discern_3elem_case(int n1, int n2, int n3)
{
	int	min;
	int	max;

	min = ft_min_nbr(ft_min_nbr(n1, n2), n3);
	max = ft_max_nbr(ft_max_nbr(n1, n2), n3);

	if (n1 == min && n3 == max)
		return (0);
	if (n3 == min && n2 == max)
		return (1);
	if (n2 == min && n1 == max)
		return (2);
	if (n3 == min && n1 == max)
		return (3);
	if (n2 == min && n3 == max)
		return (4);
	if (n1 == min && n2 == max)
		return (5);
	return (-1);
}

/**
 * Solve the 3-element stack using the cases:
 * 
 * 0: [1,2,3] -> ok
 * 1:[2,3,1] -> rra -> [1,2,3] -> ok
 * 2:[3,1,2] -> ra  -> [1,2,3] -> ok
 * 3:[3,2,1] -> sa  -> [2,3,1] -> rra -> [1,2,3] -> ok
 * 4:[2,1,3] -> sa  -> [1,2,3] -> ok
 * 5:[1,3,2] -> rra -> [2,1,3] -> sa  -> [1,2,3] -> ok
*/
static void	solve_small_ps_3(t_game **game, int case_3)
{
	if (case_3 == 1)
		rra(game);
	else if (case_3 == 2)
		ra(game);
	else if (case_3 == 3)
	{
		sa(game);
		rra(game);
	}
	else if (case_3 == 4)
		sa(game);
	else if (case_3 == 5)
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
	int	case_3;

	if ((*game)->stack_a->size <= 1)
		return ;
	if ((*game)->stack_a->size == 2)
	{
		sa(game);
		return ;
	}
	case_3 = discern_3elem_case(
			*(int *)(*game)->stack_a->head->content,
			*(int *)(*game)->stack_a->head->next->content,
			*(int *)(*game)->stack_a->head->next->next->content
			);
	solve_small_ps_3(game, case_3);
}
