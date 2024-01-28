#include "push_swap.h"

void leaks()
{
	system("leaks push_swap");
}



/**
 * 
 * 
*/
void	solve_push_swap(t_game *game)
{

	print_deque(game->stack_a->st, TRUE); //


}

void	end_all(int **ints, t_game **game)
{
	if (*game)
		del_game(game);
	if (*ints)
		free(ints); //?
}

int	main(int argc, char *argv[])
{
	int		*ints;
	int		n;
	t_game	*game;

	//atexit(leaks);
	if (argc == 1)
		return (0);
	ints = args_as_ints(argc, argv, &n);
	if (!valid_args(ints, n))
	{
		end_all(&ints, &game);
		ft_printf("Error\n");
		return (-1);
	}
	ft_putarr_ints(ints, n); //
	game = init_game(ints, n);
	if (!game)
	{
		end_all(&ints, &game);
		return (-1);
	}
	solve_push_swap(game);
	print_game_solution(game);
	end_all(&ints, &game);
	return (0);
}
