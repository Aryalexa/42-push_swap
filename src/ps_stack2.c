/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastro <macastro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:18:42 by macastro          #+#    #+#             */
/*   Updated: 2024/04/11 19:18:43 by macastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * Pop at the front.
 * It gets the head node, deletes it and return its content.
 * The deque must have been initialized with new or NULL
*/
int	ft_st_pop_head(t_stack **st)
{
	t_intnode	*popped_head;
	t_intnode	*new_head;
	int			content;

	if (!*st || (*st)->size == 0)
		return (-1);
	popped_head = (*st)->head;
	content = popped_head->num;
	new_head = popped_head->next;
	if (new_head)
		new_head->prev = NULL;
	else
		(*st)->rear = NULL;
	(*st)->head = new_head;
	popped_head->next = NULL;
	free(popped_head);
	(*st)->size--;
	return (content);
}

/**
 * Pop at the end
 * It gets the rear node, deletes it and return its content.
 * The deque must have been initialized with new or NULL
*/
int	ft_st_pop_rear(t_stack **st)
{
	t_intnode	*popped_rear;
	t_intnode	*new_rear;
	int			content;

	if (!*st || (*st)->size == 0)
		return (-1);
	popped_rear = (*st)->rear;
	content = popped_rear->num;
	new_rear = popped_rear->prev;
	if (new_rear)
		new_rear->next = NULL;
	else
		(*st)->head = NULL;
	(*st)->rear = new_rear;
	popped_rear->prev = NULL;
	free(popped_rear);
	(*st)->size--;
	return (content);
}

/**
 * Iterates the stack ’st’ and applies the function ’f’ to the content of
 * each element.
*/
void	ft_st_iter(t_stack *st, void (*f)(int))
{
	t_intnode	*cur;

	if (!f || !st)
		return ;
	cur = st->head;
	while (cur)
	{
		f(cur->num);
		cur = cur->next;
	}
}

void	ft_del_stack(t_stack **st)
{
	t_intnode	*cur;
	int			content;

	if (!*st)
		return ;
	cur = (*st)->head;
	while (cur)
	{
		content = ft_st_pop_head(st);
		cur = (*st)->head;
	}
	free(*st);
}

/**
 * Return the index of the number, -1 if not present
 */
int	ft_stack_index(t_stack *st, int n)
{
	int			i;
	t_intnode	*cur;

	i = 0;
	cur = st->head;
	while (cur)
	{
		if (cur->num == n)
			return (i);
		i++;
		cur = cur->next;
	}
	return (-1);
}
