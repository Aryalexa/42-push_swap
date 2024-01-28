#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/42-libft/libft/libft.h"

// stack
typedef struct s_stack
{
	t_deque	*st;
	char	*name;
}	t_stack;
t_stack	*ft_new_stack(char *name);
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

// utils
int		ft_intcmp(int *a, int *b);
void	skip(void *x);
void	print_deque(t_deque *dq, t_bool numbers);

// args
int		*args_as_ints(int argc, char *argv[], int *size);
t_bool	valid_args(int *ints, int n);


// ops

#endif