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

	if (n == 0 || !ints)
		return (NULL);
	game = malloc(sizeof(t_game));
	if (!game)
		return (NULL);
	game->stack_a = ft_new_stack();
	game->stack_b = ft_new_stack();
	game->sol = ft_new_deque();
	if (!game->stack_a || !game->stack_b || !game->sol)
		return (del_game(&game), NULL);
	ft_stack_dump(&game->stack_a, ints, n);
	game->min_elem = ft_min_arrint(ints, n);
	return (game);
}

void	add_to_sol(t_game **game, const char *op)
{
	char	*op_dup;

	if (!*game)
		return ;
	op_dup = ft_strdup(op);
	ft_dq_append_rear(&(*game)->sol, (void *)op_dup);
}

void	print_game_solution(t_game *game)
{
	if (game->sol->size > 0)
		print_deque(game->sol, FALSE);
}

void	del_game(t_game **game)
{
	if (!*game)
		return ;
	ft_del_stack(&(*game)->stack_a);
	ft_del_stack(&(*game)->stack_b);
	ft_clear_deque(&(*game)->sol, free);
	free(*game);
}
