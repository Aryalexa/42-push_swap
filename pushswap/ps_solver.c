#include "push_swap.h"

t_bool	is_sorted(t_stack *st, t_order order)
{
	t_node	*cur;
	t_node	*next;

	cur = st->head;
	while (cur->next)
	{
		next = cur->next;
		if (order == ASC && *(int *)cur->content > *(int *)next->content)
			return (FALSE);
		if (order == DESC && *(int *)cur->content < *(int *)next->content)
			return (FALSE);
		cur = next;
	}
	return (TRUE);
}
