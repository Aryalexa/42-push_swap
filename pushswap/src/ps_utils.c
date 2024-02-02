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
	(void)*x;
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
	//ft_printf("\n");
}
