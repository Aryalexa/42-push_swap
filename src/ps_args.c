/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macastro <macastro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 19:18:01 by macastro          #+#    #+#             */
/*   Updated: 2024/05/23 19:40:04 by macastro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	**args_as_words(int argc, char *argv[])
{
	int		i;
	char	*joined;
	char	**args;

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

static int	*words_as_ints(char **words, int n)
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
 * Are `ints` valid? 1-yes, 0-no
 * `ints` are valid when: 
 * - ints not null
 * - n > 0
 * - no dups
*/
t_bool	valid_args(int *ints, int n)
{
	int		i;
	t_bool	ok;
	t_list	*nodups_lst;
	int		(*cmp)(void *, void *);

	if (!ints || n <= 0)
		return (FALSE);
	nodups_lst = ft_lstnew(&ints[0]);
	if (!nodups_lst)
		return (FALSE);
	i = 1;
	ok = TRUE;
	cmp = (int (*)(void *, void *))ft_intcmp;
	while (i < n && ok)
	{
		if (ft_lstindex(nodups_lst, &ints[i], cmp) != -1)
			ok = FALSE;
		ft_lstadd_back(&nodups_lst, ft_lstnew(&ints[i]));
		i++;
	}
	ft_lstclear(&nodups_lst, skip);
	return (ok);
}
