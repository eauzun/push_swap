/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:00:00 by emuzun             #+#    #+#             */
/*   Updated: 2025/04/05 05:30:43 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stacks *stacks, int print)
{
	t_stack	*temp;

	if (!stacks->a || !stacks->a->next)
		return ;
	temp = stacks->a;
	stacks->a = stacks->a->next;
	temp->next = stacks->a->next;
	stacks->a->next = temp;
	if (print)
		print_operation("sa");
}

void	sb(t_stacks *stacks, int print)
{
	t_stack	*temp;

	if (!stacks->b || !stacks->b->next)
		return ;
	temp = stacks->b;
	stacks->b = stacks->b->next;
	temp->next = stacks->b->next;
	stacks->b->next = temp;
	if (print)
		print_operation("sb");
}

void	ss(t_stacks *stacks, int print)
{
	sa(stacks, 0);
	sb(stacks, 0);
	if (print)
		print_operation("ss");
}

void	pa(t_stacks *stacks, int print)
{
	t_stack	*temp;

	if (!stacks->b)
		return ;
	temp = stacks->b;
	stacks->b = stacks->b->next;
	temp->next = stacks->a;
	stacks->a = temp;
	if (print)
		print_operation("pa");
}

void	pb(t_stacks *stacks, int print)
{
	t_stack	*temp;

	if (!stacks->a)
		return ;
	temp = stacks->a;
	stacks->a = stacks->a->next;
	temp->next = stacks->b;
	stacks->b = temp;
	if (print)
		print_operation("pb");
}