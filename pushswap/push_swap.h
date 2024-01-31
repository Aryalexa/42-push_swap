#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/42-libft/libft/libft.h"

typedef enum e_order
{
	ASC = 0,
	DESC
}	t_order;

// stack
typedef t_deque	t_stack;
t_stack	*ft_new_stack(void);
void	ft_stack_dump(t_stack **stack, int *ints, int n);
void	ft_del_stack(t_stack **stack);

// game
typedef struct s_game
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		min_elem;
	t_deque	*sol;
}	t_game;
t_game	*init_game(int *ints, int n);
void	del_game(t_game **game);
void	add_to_sol(t_game **game, const char *op);
void	print_game_solution(t_game *game);

// solver functions
void	solve_small_ps(t_game **game);
t_bool	is_sorted(t_stack *st, t_order order);

// ops
void	sa(t_game **game);
void	sb(t_game **game);
void	ss(t_game **game);
void	pa(t_game **game);
void	pb(t_game **game);
void	ra(t_game **game);
void	rb(t_game **game);
void	rr(t_game **game);
void	rra(t_game **game);
void	rrb(t_game **game);
void	rrr(t_game **game);

// ops - aux
t_bool	op_swap(t_deque **st);
t_bool	op_push(t_deque **st, t_deque **from);
t_bool	op_rotate(t_deque **st);
t_bool	op_reverse_rotate(t_deque **st);

// utils
int		ft_intcmp(int *a, int *b);
void	skip(void *x);
void	print_deque(t_deque *dq, t_bool numbers);

// args
int		*args_as_ints(int argc, char *argv[], int *size);
t_bool	valid_args(int *ints, int n);

#endif
