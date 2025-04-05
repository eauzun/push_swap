/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/05 05:31:54 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	parse_args(int argc, char **argv, t_stacks *stacks)
{
	int		i;
	int		error;
	int		num;
	t_stack	*new;

	i = 1;
	while (i < argc)
	{
		error = 0;
		num = ft_atoi_check(argv[i], &error);
		if (error)
			return (0);
		new = stack_new(num);
		if (!new)
			return (0);
		stack_add_back(&(stacks->a), new);
		i++;
	}
	check_duplicates(stacks->a);
	return (1);
}

void	sort_stack(t_stacks *stacks, int size)
{
	if (is_sorted(stacks->a))
		return ;
	if (size <= 25)
		insertion_sort(stacks, size);
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
		exit_error();
	}
	size = stack_size(stacks.a);
	sort_stack(&stacks, size);
	stack_clear(&stacks.a);
	stack_clear(&stacks.b);
	return (0);
}