/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastro <macastro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:18:40 by macastro          #+#    #+#             */
/*   Updated: 2024/04/11 19:18:41 by macastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_intnode	*ft_new_intnode(t_intnode *prev, int num, t_intnode *next)
{
	t_intnode	*node;

	node = (t_intnode *)malloc(sizeof(t_intnode));
	if (!node)
		return (NULL);
	node->prev = prev;
	node->num = num;
	node->next = next;
	return (node);
}

/** 
 * t_stack is a modified t_deque 
 * It uses the a intnode but has more attributes
 * - head, rear
 * - size
 * - min, max
 * - order
*/
t_stack	*ft_new_stack(t_order order)
{
	t_stack	*st;

	st = (t_stack *)malloc(sizeof(t_stack));
	if (!st)
		return (NULL);
	st->head = NULL;
	st->rear = NULL;
	st->size = 0;
	st->order = order;
	return (st);
}

/**
 * Append
 * It adds new element at the end of the deque.
 * The deque must have been initialized with new or NULL
*/
void	ft_st_append_rear(t_stack **st, int num)
{
	t_intnode	*rear;
	t_intnode	*new_node;

	if (!*st)
		return ;
	rear = (*st)->rear;
	new_node = ft_new_intnode(rear, num, NULL);
	if (rear)
		rear->next = new_node;
	else
		(*st)->head = new_node;
	(*st)->rear = new_node;
	(*st)->size++;
}

/**
 * Append at the front.
 * It adds a new element at the beginning of the deque.
 * The deque must have been initialized with new or NULL
*/
void	ft_st_append_head(t_stack **st, int num)
{
	t_intnode	*head;
	t_intnode	*new_node;

	if (!st)
		return ;
	head = (*st)->head;
	new_node = ft_new_intnode(NULL, num, head);
	if (head)
		head->prev = new_node;
	else
		(*st)->rear = new_node;
	(*st)->head = new_node;
	(*st)->size++;
}

/**
 * test this con deque vacio y lleno
 * 
*/
void	ft_st_dump(t_stack **stack, int *ints, int n)
{
	int	i;

	if (n == 0 || !(*stack))
		return ;
	i = 0;
	while (i < n)
	{
		ft_st_append_rear(stack, ints[i]);
		i++;
	}
}
