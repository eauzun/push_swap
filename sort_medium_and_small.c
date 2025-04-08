/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium_and_small.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 00:37:26 by emuzun            #+#    #+#             */
/*   Updated: 2025/04/08 00:37:27 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void sort_two(t_stacks *stacks)
{
if (stacks->a->value > stacks->a->next->value)
sa(stacks, 1);
}

void sort_three(t_stacks *stacks)
{
int a;
int b;
int c;
a = stacks->a->value;
b = stacks->a->next->value;
c = stacks->a->next->next->value;
if (a > b && b < c && a < c)
	sa(stacks, 1);
else if (a > b && b > c)
{
	sa(stacks, 1);
	rra(stacks, 1);
}
else if (a > b && b < c && a > c)
	ra(stacks, 1);
else if (a < b && b > c && a < c)
{
	sa(stacks, 1);
	ra(stacks, 1);
}
else if (a < b && b > c && a > c)
	rra(stacks, 1);
}

static int find_min_pos(t_stack *stack)
{
int min;
int pos;
int i;
t_stack *temp;


min = stack->value;
pos = 0;
i = 0;
temp = stack;
while (temp)
{
	if (temp->value < min)
	{
		min = temp->value;
		pos = i;
	}
	temp = temp->next;
	i++;
}
return (pos);
}

void insertion_sort(t_stacks *stacks, int size)
{
int pos;
int i;
while (size > 3)
{
	pos = find_min_pos(stacks->a);
	if (pos <= size / 2)
	{
		i = 0;
		while (i++ < pos)
			ra(stacks, 1);
	}
	else
	{
		i = 0;
		while (i++ < size - pos)
			rra(stacks, 1);
	}
	pb(stacks, 1);
	size--;
}
sort_three(stacks);
while (stacks->b)
	pa(stacks, 1);
}

void sort_medium_and_small(t_stacks *stacks, int size)
{
if (size <= 1)
return ;
else if (size == 2)
sort_two(stacks);
else if (size == 3)
sort_three(stacks);
else
insertion_sort(stacks, size);
}