#include "push_swap.h"

t_stack	*ft_new_stack()
{
	return (ft_new_deque());
}

/**
 * test this con deque vacio y lleno
 * 
*/
void	ft_stack_dump(t_stack **stack, int *ints, int n)
{
	int		i;

	if (n == 0 || !(*stack))
		return ;
	i = 0;
	while (i < n)
	{
		ft_dq_append_rear(stack, &ints[i]);
		i++;
	}
}

void	ft_del_stack(t_stack **stack)
{
	ft_clear_deque(stack, skip);
}
