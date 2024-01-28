#include "push_swap.h"


/**
 * init game
 * - all elemts in stack a
 * - init stack b empty
 * - init min_elem
 * - init sol empty (a deque of strings)
*/
t_game	*init_game(int *ints, int n)
{
	t_game	*game;
	int		min;

	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);

	game->stack_a = ft_new_stack("a");
	game->stack_b = ft_new_stack("b");
	game->sol = ft_new_deque();
	if (!game->stack_a || !game->stack_b || !game->sol)
		return (del_game(&game), NULL);
	ft_stack_dump(&game->stack_a, ints, n);
	game->min_elem = ft_min_nbr_in_arr(ints, n);
	return (game);
}

void	print_game_solution(t_game *game)
{
	print_deque(game->sol, FALSE);
}

void	del_game(t_game **game)
{
	if (!*game)
		return ;
	ft_del_stack(&(*game)->stack_a);
	ft_del_stack(&(*game)->stack_b);
	free(game);
}
