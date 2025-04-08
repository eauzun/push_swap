/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:29:56 by emuzun            #+#    #+#             */
/*   Updated: 2025/04/07 23:56:17 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

t_stack	*stack_last(t_stack *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}

int	stack_min(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	if (!stack)
		return (0);
	min = stack->value;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value < min)
			min = tmp->value;
		tmp = tmp->next;
	}
	return (min);
}

int	stack_max(t_stack *stack)
{
	int		max;
	t_stack	*tmp;

	if (!stack)
		return (0);
	max = stack->value;
	tmp = stack;
	while (tmp)
	{
		if (tmp->value > max)
			max = tmp->value;
		tmp = tmp->next;
	}
	return (max);
}

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;

	if (!stack)
		return (1);
	tmp = stack;
	while (tmp->next)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	assign_index(t_stack *stack, int size)
{
	t_stack	*temp;
	t_stack	*highest;
	int		value;

	while (--size > 0)
	{
		temp = stack;
		value = INT_MIN;
		highest = NULL;
		while (temp)
		{
			if (temp->value > value && temp->index == 0)
			{
				value = temp->value;
				highest = temp;
			}
			temp = temp->next;
		}
		if (highest)
			highest->index = size;
	}
}
