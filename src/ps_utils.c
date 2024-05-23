/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastro <macastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:18:47 by macastro          #+#    #+#             */
/*   Updated: 2024/05/23 19:41:14 by macastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_intcmp(int *a, int *b)
{
	return (*a - *b);
}

/**
 * 	void (*)(void *) skip

*/
void	skip(void *x)
{
	(void)x;
}

/// ------------- prints ---------------

/**
 * print number + separator
*/
static void	ft_putnbr(void *x)
{
	ft_printf("%i ", *(int *)x);
}

/**
 * print number + separator
*/
static void	ft_putstr(void *x)
{
	ft_printf("%s\n", (char *)x);
}

void	print_deque(t_deque *dq, t_bool numbers)
{
	void	(*prnt)(void *);

	if (numbers)
		prnt = (void (*)(void *))ft_putnbr;
	else
		prnt = (void (*)(void *))ft_putstr;
	ft_iter_deque(dq, prnt);
}
