/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:00:00 by emuzun            #+#    #+#             */
/*   Updated: 2025/04/08 17:52:22 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    exit_error(t_stacks *stacks)
{
    if (stacks)
    {
        if (stacks->a)
            stack_clear(&stacks->a);
        if (stacks->b)
            stack_clear(&stacks->b);
    }
    write(2, "Error\n", 6);
    exit(1);
}


void	print_operation(char *op)
{
	int	i;

	i = 0;
	while (op[i])
	{
		write(1, &op[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int    check_duplicates(t_stack *stack)
{
    t_stack    *i;
    t_stack    *j;

    i = stack;
    while (i)
    {
        j = i->next;
        while (j)
        {
            if (i->value == j->value)
                return (1);
            j = j->next;
        }
        i = i->next;
    }
    return (0);
}
