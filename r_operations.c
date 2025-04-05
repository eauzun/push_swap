/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/05 14:51:11 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stacks *stacks, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stacks->a || !stacks->a->next)
		return ;
	temp = stacks->a;
	stacks->a = stacks->a->next;
	last = stack_last(stacks->a);
	temp->next = NULL;
	last->next = temp;
	if (print)
		print_operation("ra");
}

void	rb(t_stacks *stacks, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stacks->b || !stacks->b->next)
		return ;
	temp = stacks->b;
	stacks->b = stacks->b->next;
	last = stack_last(stacks->b);
	temp->next = NULL;
	last->next = temp;
	if (print)
		print_operation("rb");
}

void	rr(t_stacks *stacks, int print)
{
	ra(stacks, 0);
	rb(stacks, 0);
	if (print)
		print_operation("rr");
}

