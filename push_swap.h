/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:28:54 by emuzun            #+#    #+#             */
/*   Updated: 2025/04/08 18:03:26 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#  define INT_MAX 2147483647
#  define INT_MIN -2147483648

# include <stdlib.h>
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

typedef struct s_stacks
{
	t_stack	*a;
	t_stack	*b;
}	t_stacks;


t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *new);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_clear(t_stack **stack);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);
int		is_sorted(t_stack *stack);
void	assign_index(t_stack *stack, int size);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
void	free_split(char **split);
void	sa(t_stacks *stacks, int print);
void	sb(t_stacks *stacks, int print);
void	ss(t_stacks *stacks, int print);
void	pa(t_stacks *stacks, int print);
void	pb(t_stacks *stacks, int print);
void	ra(t_stacks *stacks, int print);
void	rb(t_stacks *stacks, int print);
void	rr(t_stacks *stacks, int print);
void	rra(t_stacks *stacks, int print);
void	rrb(t_stacks *stacks, int print);
void	rrr(t_stacks *stacks, int print);
void	sort_stack(t_stacks *stacks, int size);
void	sort_two(t_stacks *stacks);
void	sort_three(t_stacks *stacks);
void	insertion_sort(t_stacks *stacks, int size);
void	sort_medium_and_small(t_stacks *stacks, int size);
void	radix_sort(t_stacks *stacks, int size);
void	exit_error(t_stacks *stacks);
int		ft_atoi_check(const char *str, int *error);
void	print_operation(char *op);
int		ft_strcmp(char *s1, char *s2);
int	check_duplicates(t_stack *stack);
int		parse_args(int argc, char **argv, t_stacks *stacks);

#endif