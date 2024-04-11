/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastro <macastro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:18:54 by macastro          #+#    #+#             */
/*   Updated: 2024/04/11 19:18:55 by macastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	solve_push_swap(t_game **game)
{
	if (is_sorted((*game)->stack_a))
		return ;
	if ((*game)->stack_a->size <= 3)
		solve_small_ps(game);
	else
		solve_big_ps(game);
}

void	end_game(int **ints, t_game **game)
{
	if (*game)
		del_game(game);
	if (*ints)
		free(*ints);
}

int	main(int argc, char *argv[])
{
	int		*ints;
	int		n;
	t_game	*game;

	if (argc == 1)
		return (0);
	ints = args_as_ints(argc, argv, &n);
	game = init_game(ints, n);
	if (!valid_args(ints, n) | !game)
	{
		end_game(&ints, &game);
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	solve_push_swap(&game);
	print_game_solution(game);
	end_game(&ints, &game);
	return (0);
}
