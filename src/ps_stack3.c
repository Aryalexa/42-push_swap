/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastro <macastro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:18:45 by macastro          #+#    #+#             */
/*   Updated: 2024/04/11 19:18:46 by macastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_st_max(t_stack *st)
{
	int			max;
	t_intnode	*cur;

	cur = st->head;
	max = cur->num;
	while (cur)
	{
		if (max < cur->num)
			max = cur->num;
		cur = cur->next;
	}
	return (max);
}

static int	ft_st_min(t_stack *st)
{
	int			min;
	t_intnode	*cur;

	cur = st->head;
	min = cur->num;
	while (cur)
	{
		if (min > cur->num)
			min = cur->num;
		cur = cur->next;
	}
	return (min);
}

/**
 * ft_csorted_stack_index_asc.
 * return index:
 * - if rear < n < head -> 0
 * - new max or new min -> pos of first in the order (min)
 * - otherwise, go to the correct position: until cur < n < next -> next pos
*/
static int	ft_csst_idx_asc(t_stack *st, int n)
{
	int			i;
	t_intnode	*cur;
	t_intnode	*next;

	if (st->rear->num < n
		&& n < st->head->num)
		i = 0;
	else if (n > ft_st_max(st) || n < ft_st_min(st))
		i = ft_stack_index(st, ft_st_min(st));
	else
	{
		i = 1;
		cur = st->head;
		next = cur->next;
		while (!(cur->num < n && n < next->num))
		{
			i++;
			cur = cur->next;
			next = cur->next;
		}
	}
	return (i);
}

/**
 * ft_csorted_stack_index_desc.
 * return index:
 * - if rear > n > head -> 0
 * - new max or new min -> pos of first in the order (max)
 * - otherwise, go to the correct position: until cur > n > next -> next pos
*/
static int	ft_csst_idx_desc(t_stack *st, int n)
{
	int			i;
	t_intnode	*cur;
	t_intnode	*next;

	if (st->rear->num > n
		&& n > st->head->num)
		i = 0;
	else if (n > ft_st_max(st) || n < ft_st_min(st))
		i = ft_stack_index(st, ft_st_max(st));
	else
	{
		i = 1;
		cur = st->head;
		next = cur->next;
		while (!(cur->num > n && n > next->num))
		{
			i++;
			cur = cur->next;
			next = cur->next;
		}
	}
	return (i);
}

/**
 * Returns the number's position in the stack or the position 
 * where the number should be inserted if it's not present
 * Assumes circular order (ascending or descending).
*/
int	ft_csorted_stack_index(t_stack *st, int n)
{
	if (st->order == ASC)
		return (ft_csst_idx_asc(st, n));
	else
		return (ft_csst_idx_desc(st, n));
}
