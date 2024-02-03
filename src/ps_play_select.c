#include "push_swap.h"

/**
 * Count moves using rr op
 * If going A -> B(desc)
 * - how many ra moves are needed to put the number at the top of A?
 * - how many rb moves are needed to arrange B so we can push n to its top?
 * This function return the max of both.
*/
static int	moves_w_rr(t_stack *st_src, t_stack *st_dst, int n)
{
	int	moves_src;
	int	moves_dst;

	moves_src = ft_stack_index(st_src, n);
	moves_dst = ft_csorted_stack_index(st_dst, n);
	return (ft_max_nbr(moves_src, moves_dst));
}

/**
 * Count moves using rrr op
 * If going B -> A(asc)
 * - how many rb moves are needed to put the number at the top of B?
 * - how many ra moves are needed to arrange A so we can push n to its top?
 * This function return the max of both.
*/
static int	moves_w_rrr(t_stack *st_src, t_stack *st_dst, int n)
{
	int	moves_src;
	int	moves_dst;
	int	idx_src;
	int	idx_dst;

	idx_src = ft_stack_index(st_src, n);
	idx_dst = ft_csorted_stack_index(st_dst, n);
	moves_src = 0;
	moves_dst = 0;
	if (idx_src > 0)
		moves_src = st_src->size - idx_src;
	if (idx_dst > 0)
		moves_dst = st_dst->size - idx_dst;
	return (ft_max_nbr(moves_src, moves_dst));
}

/**
 * Count moves using rrx and rx ops
 * If going A -> B(desc)
 * - how many rra moves are needed to put the number at the top of A?
 * - how many rb moves are needed to arrange B so we can push n to its top?
 * This function return the sum of both.
*/
static int	moves_w_rr_r(t_stack *st_src, t_stack *st_dst, int n)
{
	int	moves_src;
	int	moves_dst;
	int	idx_src;

	idx_src = ft_stack_index(st_src, n);
	moves_src = 0;
	if (idx_src > 0)
		moves_src = st_src->size - idx_src;
	moves_dst = ft_csorted_stack_index(st_dst, n);
	return (moves_src + moves_dst);
}

/**
 * Count moves using rx and rrx ops
 * If going A -> B(desc)
 * - how many ra moves are needed to put the number at the top of A?
 * - how many rrb moves are needed to arrange B so we can push n to its top?
 * This function return the sum of both.
*/
static int	moves_w_r_rr(t_stack *st_src, t_stack *st_dst, int n)
{
	int	moves_src;
	int	moves_dst;
	int	idx_dst;

	moves_src = ft_stack_index(st_src, n);
	idx_dst = ft_csorted_stack_index(st_dst, n);
	moves_dst = 0;
	if (idx_dst > 0)
		moves_dst = st_dst->size - idx_dst;
	return (moves_src + moves_dst);
}

/**
 * Select cheapest play.
 * Return the cost (numer of moves) and load the play type.
*/
int	cheapest_play(t_stack *st_src, t_stack *st_dst, int num, t_play *rcase)
{
	int	n_moves;

	n_moves = st_src->size * 100;
	if (n_moves > moves_w_rr(st_src, st_dst, num))
	{
		n_moves = moves_w_rr(st_src, st_dst, num);
		*rcase = CASE_RR;
	}
	if (n_moves > moves_w_rrr(st_src, st_dst, num))
	{
		n_moves = moves_w_rrr(st_src, st_dst, num);
		*rcase = CASE_RRR;
	}
	if (n_moves > moves_w_rr_r(st_src, st_dst, num))
	{
		n_moves = moves_w_rr_r(st_src, st_dst, num);
		*rcase = CASE_RR_R;
	}
	if (n_moves > moves_w_r_rr(st_src, st_dst, num))
	{
		n_moves = moves_w_r_rr(st_src, st_dst, num);
		*rcase = CASE_R_RR;
	}
	return (n_moves);
}
