/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_ops_aux.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastro <macastro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:18:13 by macastro          #+#    #+#             */
/*   Updated: 2024/04/11 19:18:14 by macastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * It swaps first two elements
 * return True if success
*/
t_bool	op_swap(t_stack **st)
{
	int	n1;
	int	n2;

	if ((*st)->size < 2)
		return (FALSE);
	n1 = ft_st_pop_head(st);
	n2 = ft_st_pop_head(st);
	ft_st_append_head(st, n1);
	ft_st_append_head(st, n2);
	return (TRUE);
}

/**
 * It takes the first element from `from` and 
 * pushes it to the main stack `st`.
 * If `from` is empty, no changes.
 * return True if success
*/
t_bool	op_push(t_stack **st, t_stack **from)
{
	int	n;

	if ((*from)->size < 1)
		return (FALSE);
	n = ft_st_pop_head(from);
	ft_st_append_head(st, n);
	return (TRUE);
}

/**
 * It moves the first element to the last position so
 * the rest of the elements move one position up.
 * return True if success
*/
t_bool	op_rotate(t_stack **st)
{
	int	n;

	if ((*st)->size < 2)
		return (FALSE);
	n = ft_st_pop_head(st);
	ft_st_append_rear(st, n);
	return (TRUE);
}

/**
 * It moves the last element to the first position so
 * the rest of the elements move one position down.
 * return True if success
*/
t_bool	op_reverse_rotate(t_stack **st)
{
	int	n;

	if ((*st)->size < 2)
		return (FALSE);
	n = ft_st_pop_rear(st);
	ft_st_append_head(st, n);
	return (TRUE);
}
