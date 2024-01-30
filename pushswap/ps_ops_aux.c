/**
 * sa swap a: Intercambia los dos primeros elementos del stack a. No hace nada si hay uno o menos elementos.
 * sb swap b: Intercambia los dos primeros elementos del stack b. No hace nada si hay uno o menos elementos.
 * ss swap a y swap b alavez.
 * pa push a: Toma el primer elemento del stack b y lo pone el primero en el stack a. No hace nada si b está vacío.
 * pb push b: Toma el primer elemento del stack a y lo pone el primero en el stack b. No hace nada si a está vacío.
 * ra rotate a: Desplaza hacia arriba todos los elementos del stack a una posición, de forma que el primer elemento se convierte en el último.
 * rb rotate b: Desplaza hacia arriba todos los elementos del stack b una posición, de forma que el primer elemento se convierte en el último.
 * rr ra y rb al mismo tiempo.
 * rra reverse rotate a: Desplaza hacia abajo todos los elementos del stack a una posición, de forma que el último elemento se convierte en el primero.
 * rrb reverse rotate b: Desplaza hacia abajo todos los elementos del stack b una posición, de forma que el último elemento se convierte en el primero.
 * rrr rra y rrb al mismo tiempo.
*/

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
