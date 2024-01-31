#include "push_swap.h"

/**
 * It swaps first two elements
 * return True if success
*/
t_bool	op_swap(t_deque **st)
{
	int	*n1;
	int	*n2;

	if ((*st)->size < 2)
		return (FALSE);
	n1 = (int *)ft_dq_pop_head(st);
	n2 = (int *)ft_dq_pop_head(st);
	ft_dq_append_head(st, (void *)n1);
	ft_dq_append_head(st, (void *)n2);
	return (TRUE);
}

/**
 * It takes the first element from `from` and 
 * pushes it to the main stack `st`.
 * If `from` is empty, no changes.
 * return True if success
*/
t_bool	op_push(t_deque **st, t_deque **from)
{
	int	*n;

	if ((*from)->size < 1)
		return (FALSE);
	n = (int *)ft_dq_pop_head(from);
	ft_dq_append_head(st, (void *)n);
	return (TRUE);
}

/**
 * It moves the first element to the last position so
 * the rest of the elements move one position up.
 * return True if success
*/
t_bool	op_rotate(t_deque **st)
{
	int	*n;

	if ((*st)->size < 2)
		return (FALSE);
	n = (int *)ft_dq_pop_head(st);
	ft_dq_append_rear(st, (void *)n);
	return (TRUE);
}

/**
 * It moves the last element to the first position so
 * the rest of the elements move one position down.
 * return True if success
*/
t_bool	op_reverse_rotate(t_deque **st)
{
	int	*n;

	if ((*st)->size < 2)
		return (FALSE);
	n = (int *)ft_dq_pop_rear(st);
	ft_dq_append_head(st, (void *)n);
	return (TRUE);
}
