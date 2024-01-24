#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/42-libft/libft/libft.h"

typedef t_deque	t_stack;

// utils
int		ft_intcmp(int *a, int *b);
void	skip(void *x);
void	ft_putnbr(void *x);
void	print_deque(t_deque *dq);

// frees
//change to void**? and move to libft?
void	ft_free_arrstr(char **words);

// args
int		*args_as_ints(int argc, char *argv[], int *size);
int		valid_args(int *ints, int n);


// ops

#endif