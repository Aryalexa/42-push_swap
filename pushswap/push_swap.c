#include "push_swap.h"


void	ft_putnbr(void *x)
{
	ft_printf("%i,", *(int *)x);
}

void	skip(void *x)
{
	(void)*x;
}

void leaks()
{
	system("leaks push_swap");
}

void print_deque(t_deque *dq)
{
	void (*prnt)(void *);
	prnt = (void (*)(void*))ft_putnbr;
	ft_iter_deque(dq, prnt);
	ft_printf("\n");
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

char	**args_as_words(int argc, char *argv[])
{
	int		i;
	char	*joined;
	char 	**args;

	joined = ft_strdup("");
	if (!joined)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		joined = ft_strjoin_realloc(&joined, argv[i]);
		joined = ft_strjoin_realloc(&joined, " ");
		i++;
	}
	args = ft_split(joined, ' ');
	free(joined);
	return (args);
}

void ft_free_arrstr(char **words)
{
	int	i;

	i = 0;
	while (words[i])
	{
		free(words[i]);
		i++;
	}
	free(words);
}

int *words_as_ints(char **words, int n)
{
	int		*ints;
	int		i;

	ints = malloc(n * sizeof(int));
	if (!ints)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (ft_atoi_secure(words[i], &ints[i]) < 0)
		{
			free(ints);
			return (NULL);
		}
		i++;
	}
	return (ints);
}

int	*args_as_ints(int argc, char *argv[], int *size)
{
	char	**args;
	int		*ints;

	args = args_as_words(argc, argv);
	*size = ft_count_arrstr(args);
	ints = words_as_ints(args, *size);
	ft_free_arrstr(args);
	if (!ints)
		return (NULL);
	return (ints);
}

/**
 * return instructions???
*/
void solve_push_swap(int *ints, int n)
{
	t_stack	*a;
	t_stack	*b;

	load_stack_a(&a, n, ints);
	b = ft_new_deque();
	if (!a || !b)
		return ;

	print_deque(a);

	ft_clear_deque(&a, (void (*)(void *))skip);
	ft_clear_deque(&b, skip);

}
int ft_intcmp(int *a, int *b)
{
	return (*a - *b);
}

/**
 * Are `ints` valid? 1-yes, 0-no
 * `ints` are valid when: 
 * - no dups
*/
int valid(int *ints, int n)
{
	t_list	*nodups;
	int		i;
	int		*(*cmp)(void *, void *);


	nodups = ft_lstnew(&ints[0]);
	i = 1;
	cmp = (int *(*)(void *, void *))ft_intcmp;
	while (i < n)
	{
		if (ft_lstindex(nodups, &ints[i], cmp) != -1)
			return (0);
		ft_lstadd_back(&nodups, ft_lstnew(&ints[i]));
		i++;
	}
	ft_lstclear(&nodups, skip);
	return (1);
}

int	main(int argc, char *argv[])
{
	int	*ints;
	int	n;

	//atexit(leaks);
	if (argc == 1)
		return (0);
	ints = args_as_ints(argc, argv, &n);
	if (!ints || n == 0 || !valid(ints, n))
	{
		ft_printf("Error\n");
		return (-1);
	}

	ft_putarr_ints(ints, n);

	solve_push_swap(ints, n);

	free(ints);


	return (0);
}
