#include "push_swap.h"

t_stack	*ft_new_stack(char *name)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->name = ft_strdup(name);
	stack->st = ft_new_deque();
	if (!stack->name || !stack->st)
	{
		ft_del_stack(&stack);
		return (NULL);
	}
	return (stack);
}

/**
 * test this con deque vacio y lleno
 * 
*/
void	ft_stack_dump(t_stack **stack, int *ints, int n)
{
	int		i;
	t_deque	*a;

	if (n == 0 || !stack || !(*stack)->st)
		return ;
	a = (*stack)->st;
	i = 0;
	while (i < n)
	{
		ft_append(&a, &ints[i]);
		i++;
	}
}



void	ft_del_stack(t_stack **stack)
{
	if (!*stack)
		return ;
	if ((*stack)->name)
		free((*stack)->name);
	ft_clear_deque((*stack)->st, skip);
	free(*stack);
}
