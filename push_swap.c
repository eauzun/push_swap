/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:00:00 by emuzun            #+#    #+#             */
/*   Updated: 2025/04/08 17:08:30 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*join_argv(int argc, char **argv)
{
	char	*str;
	char	*tmp;
	int		i;

	str = ft_strdup("");
	i = 1;
	while (i < argc)
	{
		tmp = ft_strjoin(str, " ");
		free(str);
		str = ft_strjoin(tmp, argv[i]);
		free(tmp);
		i++;
	}
	return (str);
}

static int	process_arg(char *arg, t_stacks *stacks)
{
	int		error;
	int		num;
	t_stack	*new;

	error = 0;
	num = ft_atoi_check(arg, &error);
	if (error)
		return (0);
	new = stack_new(num);
	if (!new)
		return (0);
	stack_add_back(&(stacks->a), new);
	return (1);
}

int	parse_args(int argc, char **argv, t_stacks *stacks)
{
	char	*joined_str;
	char	**args;
	int		i;

	joined_str = join_argv(argc, argv);
	if (!joined_str)
		exit_error(stacks);
	args = ft_split(joined_str, ' ');
	free(joined_str);
	if (!args)
		exit_error(stacks);
	i = 0;
	while (args[i])
	{
		if (!process_arg(args[i], stacks))
		{
			free_split(args);
			exit_error(stacks);
		}
		i++;
	}
	free_split(args);
	if (check_duplicates(stacks->a))
		exit_error(stacks);
	return (1);
}

void	sort_stack(t_stacks *stacks, int size)
{
	if (is_sorted(stacks->a))
		return ;
	if (size <= 74)
		sort_medium_and_small(stacks, size);
	else
		radix_sort(stacks, size);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			size;

	if (argc < 2)
		return (0);
	stacks.a = NULL;
	stacks.b = NULL;
	if (!parse_args(argc, argv, &stacks))
	{
		stack_clear(&stacks.a);
		exit_error(&stacks);
	}
	size = stack_size(stacks.a);
	sort_stack(&stacks, size);
	stack_clear(&stacks.a);
	stack_clear(&stacks.b);
	return (0);
}