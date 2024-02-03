#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/42-libft/libft/libft.h"

typedef enum e_order
{
	ASC = 0,
	DESC
}	t_order;

typedef enum e_dir
{
	A2B = 0,
	B2A
}	t_dir;

typedef enum e_play
{
	CASE_RR = 0,
	CASE_RRR = 1,
	CASE_RR_R = 2,
	CASE_R_RR
}	t_play;

typedef enum e_3case
{
	PS_123 = 0,
	PS_231 = 1,
	PS_312 = 2,
	PS_321 = 3,
	PS_213 = 4,
	PS_132 = 5,
	PS_ERR
}	t_3case;

// stack
typedef struct s_intnode
{
	struct s_intnode	*prev;
	int					num;
	struct s_intnode	*next;
}	t_intnode;
typedef struct s_stack
{
	t_intnode	*head;
	t_intnode	*rear;
	int			size;
	int			min;
	int			max;
	t_order		order;
}	t_stack;
t_stack	*ft_new_stack(t_order order);
void	ft_st_append_rear(t_stack **st, int num);
void	ft_st_append_head(t_stack **st, int num);
void	ft_st_dump(t_stack **stack, int *ints, int n);
int		ft_st_pop_head(t_stack **st);
int		ft_st_pop_rear(t_stack **st);
void	ft_st_iter(t_stack *st, void (*f)(int));
void	ft_del_stack(t_stack **st);
int		ft_stack_index(t_stack *st, int n);
int		ft_csorted_stack_index(t_stack *st, int n);

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
void	apply_op_on_game(t_game **game, char *valid_op);

// solver functions
void	solve_small_ps(t_game **game);
t_bool	is_sorted(t_stack *st);
void	solve_big_ps(t_game **game);
int		cheapest_play(t_stack *st_src, t_stack *st_dst, int num, t_play *rcase);
void	apply_play_moves(t_game **game, t_dir ps_dir, int num, t_play play);

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
t_bool	op_swap(t_stack **st);
t_bool	op_push(t_stack **st, t_stack **from);
t_bool	op_rotate(t_stack **st);
t_bool	op_reverse_rotate(t_stack **st);

// utils
int		ft_intcmp(int *a, int *b);
void	skip(void *x);
void	print_deque(t_deque *dq, t_bool numbers);

// args
int		*args_as_ints(int argc, char *argv[], int *size);
t_bool	valid_args(int *ints, int n);

#endif
