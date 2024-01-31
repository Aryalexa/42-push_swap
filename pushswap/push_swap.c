#include "push_swap.h"

void	leaks(void)
{
	system("leaks push_swap");
}


void	solve_big_ps(t_game **game)
{
	ft_printf("BIG!\n");
	return ;

	if ((*game)->stack_a->size > 3)
		pb(game);
	if ((*game)->stack_a->size > 3)
		pb(game);
	// .. continue
}

/**
 * 
 * 
*/
void	solve_push_swap(t_game **game)
{
	//print_deque((*game)->stack_a, TRUE); //
	if (is_sorted((*game)->stack_a, ASC))
		return ;
	if ((*game)->stack_a->size <= 3)
		solve_small_ps(game);
	else
		solve_big_ps(game);
}

void	end_game(int **ints, t_game **game)
{
	if (*game)
	{
		del_game(game);
	}
	if (*ints)
	{
		free(*ints);
	}
}

int	main(int argc, char *argv[])
{
	int		*ints;
	int		n;
	t_game	*game;

	//atexit(leaks);
	if (argc == 1)
		return (0);
	game = NULL;
	ints = args_as_ints(argc, argv, &n);
	if (!valid_args(ints, n))
	{
		end_game(&ints, &game);
		ft_printf("Error\n");
		return (-1);
	}
	game = init_game(ints, n);
	if (!game)
	{
		ft_printf("no game\n"); // ---
		end_game(&ints, &game);
		return (-1);
	}
	ft_printf("*game*\n"); // ---
	solve_push_swap(&game);
	print_game_solution(game);
	end_game(&ints, &game);
	return (0);
}
