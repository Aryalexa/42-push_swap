#include "push_swap.h"

/**
 * Apply as many rr as we can, and then the single rotations
 * Dont forget the single final push
*/
static void	apply_rr(t_game **game, t_dir ps_dir, int num)
{
	if (ps_dir == A2B)
	{
		while ((*game)->stack_a->head->num != num
			&& ft_csorted_stack_index((*game)->stack_b, num) > 0)
			rr(game);
		while ((*game)->stack_a->head->num != num)
			ra(game);
		while (ft_csorted_stack_index((*game)->stack_b, num) > 0)
			rb(game);
		pb(game);
	}
	else
	{
		while ((*game)->stack_b->head->num != num
			&& ft_csorted_stack_index((*game)->stack_a, num) > 0)
			rr(game);
		while ((*game)->stack_b->head->num != num)
			rb(game);
		while (ft_csorted_stack_index((*game)->stack_a, num) > 0)
			ra(game);
		pa(game);
	}
}

/**
 * Apply as many rrr as we can, and then the single reverse rotations
 * Dont forget the single final push
*/
static void	apply_rrr(t_game **game, t_dir ps_dir, int num)
{
	if (ps_dir == A2B)
	{
		while ((*game)->stack_a->head->num != num
			&& ft_csorted_stack_index((*game)->stack_b, num) > 0)
			rrr(game);
		while ((*game)->stack_a->head->num != num)
			rra(game);
		while (ft_csorted_stack_index((*game)->stack_b, num) > 0)
			rrb(game);
		pb(game);
	}
	else
	{
		while ((*game)->stack_b->head->num != num
			&& ft_csorted_stack_index((*game)->stack_a, num) > 0)
			rrr(game);
		while ((*game)->stack_b->head->num != num)
			rrb(game);
		while (ft_csorted_stack_index((*game)->stack_a, num) > 0)
			rra(game);
		pa(game);
	}
}

/**
 * Apply rra and rb if A2B
 * Apply rrb and ra if B2A
 * Dont forget the single final push
*/
static void	apply_rr_r(t_game **game, t_dir ps_dir, int num)
{
	if (ps_dir == A2B)
	{
		while ((*game)->stack_a->head->num != num)
			rra(game);
		while (ft_csorted_stack_index((*game)->stack_b, num) > 0)
			rb(game);
		pb(game);
	}
	else
	{
		while ((*game)->stack_b->head->num != num)
			rrb(game);
		while (ft_csorted_stack_index((*game)->stack_a, num) > 0)
			ra(game);
		pa(game);
	}
}

/**
 * Apply ra and rrb if A2B
 * Apply rb and rra if B2A
 * Dont forget the single final push
*/
static void	apply_r_rr(t_game **game, t_dir ps_dir, int num)
{
	if (ps_dir == A2B)
	{
		while ((*game)->stack_a->head->num != num)
			ra(game);
		while (ft_csorted_stack_index((*game)->stack_b, num) > 0)
			rrb(game);
		pb(game);
	}
	else
	{
		while ((*game)->stack_b->head->num != num)
			rb(game);
		while (ft_csorted_stack_index((*game)->stack_a, num) > 0)
			rra(game);
		pa(game);
	}
}

void	apply_play_moves(t_game **game, t_dir ps_dir, int num, t_play play)
{
	if (play == CASE_RR)
		apply_rr(game, ps_dir, num);
	if (play == CASE_RRR)
		apply_rrr(game, ps_dir, num);
	if (play == CASE_RR_R)
		apply_rr_r(game, ps_dir, num);
	if (play == CASE_R_RR)
		apply_r_rr(game, ps_dir, num);
}
