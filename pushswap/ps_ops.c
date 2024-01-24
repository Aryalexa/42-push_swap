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
*/
void	swap(t_stack **st)
{
	int	*n1;
	int	*n2;

	if ((*st)->size < 2)
		return ;
	n1 = (int *)ft_pop_left(st);
	n2 = (int *)ft_pop_left(st);
	ft_append_left(st, (void *)n1);
	ft_append_left(st, (void *)n2);
}

/**
 * It takes the first element from `other` and 
 * pushes it to the main stack `st`.
 * If `other` is empty, no changes.
*/
void	push(t_stack **st, t_stack **other)
{
	int	*n;

	if ((*other)->size == 0)
		return ;
	n = (int *)ft_pop_left(other);
	ft_append_left(st, (void *)n);
}

/**
 * It moves the first element to the last position so
 * the rest of the elements move one position up.
*/
void	rotate(t_stack **st)
{
	int	*n;

	if ((*st)->size == 0)
		return ;
	n = (int *)ft_pop_left(st);
	ft_append(st, (void *)n);
}

/**
 * It moves the last element to the first position so
 * the rest of the elements move one position down.
*/
void	reverse_rotate(t_stack **st)
{
	int	*n;

	if ((*st)->size == 0)
		return ;
	n = (int *)ft_pop(st);
	ft_append_left(st, (void *)n);
}
