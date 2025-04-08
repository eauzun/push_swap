/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:00:00 by emuzun            #+#    #+#             */
/*   Updated: 2025/04/08 16:36:11 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stacks *stacks, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stacks->a || !stacks->a->next)
		return ;
	temp = stacks->a;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = stacks->a;
	stacks->a = last;
	if (print)
		print_operation("rra");
}

void	rrb(t_stacks *stacks, int print)
{
	t_stack	*temp;
	t_stack	*last;

	if (!stacks->b || !stacks->b->next)
		return ;
	temp = stacks->b;
	while (temp->next->next)
		temp = temp->next;
	last = temp->next;
	temp->next = NULL;
	last->next = stacks->b;
	stacks->b = last;
	if (print)
		print_operation("rrb");
}
void	rrr(t_stacks *stacks, int print)
{
	rra(stacks, 0);
	rrb(stacks, 0);
	if (print)
		print_operation("rrr");
}
