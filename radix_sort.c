/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 12:00:00 by user              #+#    #+#             */
/*   Updated: 2025/04/05 05:31:34 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}

void	radix_sort(t_stacks *stacks, int size)
{
	int	i;
	int	j;
	int	max_bits;

	assign_index(stacks->a, size + 1);
	max_bits = get_max_bits(size);
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			if (((stacks->a->index >> i) & 1) == 1)
				ra(stacks, 1);
			else
				pb(stacks, 1);
			j++;
		}
		while (stacks->b)
			pa(stacks, 1);
		i++;
	}
}