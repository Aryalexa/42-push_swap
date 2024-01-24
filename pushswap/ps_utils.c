#include "push_swap.h"

int	ft_intcmp(int *a, int *b)
{
	return (*a - *b);
}


void	skip(void *x)
{
	(void)*x;
}

/// ------------- prints ---------------

void	ft_putnbr(void *x)
{
	ft_printf("%i,", *(int *)x);
}

void	print_deque(t_deque *dq)
{
	void	(*prnt)(void *);

	prnt = (void (*)(void *))ft_putnbr;
	ft_iter_deque(dq, prnt);
	ft_printf("\n");
}
