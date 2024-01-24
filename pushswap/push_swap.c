#include "push_swap.h"

void leaks()
{
	system("leaks push_swap");
}

void	load_stack_a(t_stack **a, int n, int *ints)
{
	int	i;

	*a = NULL;
	i = 0;
	while (i < n)
	{
		ft_append(a, &ints[i]);
		i++;
	}
}

/**
 * return/print instructions???
 * 
*/
void	solve_push_swap(int *ints, int n)
{
	t_stack	*a;
	t_stack	*b;

	load_stack_a(&a, n, ints);
	b = ft_new_deque();
	if (!a || !b)
		return ;
	//solve here
	print_deque(a);

	ft_clear_deque(&a, (void (*)(void *))skip);
	ft_clear_deque(&b, skip);

}

int	main(int argc, char *argv[])
{
	int	*ints;
	int	n;

	//atexit(leaks);
	if (argc == 1)
		return (0);
	ints = args_as_ints(argc, argv, &n);
	if (!ints || n == 0 || !valid_args(ints, n))
	{
		ft_printf("Error\n");
		return (-1);
	}

	ft_putarr_ints(ints, n);

	solve_push_swap(ints, n);

	free(ints);


	return (0);
}
