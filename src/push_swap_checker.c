/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastro <macastro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:18:51 by macastro          #+#    #+#             */
/*   Updated: 2024/04/11 19:18:52 by macastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_bool	valid_op(char *op)
{
	if (op && (!ft_strncmp(op, "ss", 3)
			|| !ft_strncmp(op, "sa", 3) || !ft_strncmp(op, "sb", 3)
			|| !ft_strncmp(op, "pa", 3) || !ft_strncmp(op, "pb", 3)
			|| !ft_strncmp(op, "ra", 3) || !ft_strncmp(op, "rra", 4)
			|| !ft_strncmp(op, "rb", 3) || !ft_strncmp(op, "rrb", 4)
			|| !ft_strncmp(op, "rr", 3) || !ft_strncmp(op, "rrr", 4))
	)
		return (TRUE);
	return (FALSE);
}

t_deque	*read_solution(t_deque **final_sol)
{
	t_deque	*sol;
	char	*op;

	sol = ft_new_deque();
	if (!sol)
		return (NULL);
	op = get_next_line(0);
	while (op)
	{
		op[ft_strlen(op) - 1] = '\0';
		if (!valid_op(op))
		{
			free(op);
			ft_clear_deque(&sol, free);
			return (NULL);
		}
		ft_dq_append_rear(&sol, (void *)op);
		op = get_next_line(0);
	}
	*final_sol = sol;
	return (sol);
}

t_bool	check_solution(t_game *game, t_deque *sol)
{
	t_node	*cur;

	cur = sol->head;
	while (cur)
	{
		apply_op_on_game(&game, cur->content);
		cur = cur->next;
	}
	return (is_sorted(game->stack_a) && game->stack_b->size == 0);
}

void	end_check(int **ints, t_game **game, t_deque **sol)
{
	if (*game)
		del_game(game);
	if (*ints)
		free(*ints);
	if (*sol)
		ft_clear_deque(sol, free);
}

int	main(int argc, char *argv[])
{
	int		*ints;
	int		n;
	t_game	*game;
	t_deque	*solution;

	if (argc == 1)
		return (0);
	ints = args_as_ints(argc, argv, &n);
	game = init_game(ints, n);
	if (!valid_args(ints, n) | !game || !read_solution(&solution))
	{
		end_check(&ints, &game, &solution);
		ft_putstr_fd("Error\n", 2);
		return (-1);
	}
	if (check_solution(game, solution))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	end_check(&ints, &game, &solution);
	return (0);
}
