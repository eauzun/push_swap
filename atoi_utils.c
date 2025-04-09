/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emuzun <emuzun@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 00:12:35 by emuzun            #+#    #+#             */
/*   Updated: 2025/04/09 00:12:36 by emuzun           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"push_swap.h"

static int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int	check_overflow(long nb, int sign, char c)
{
	long int	tmp;

	tmp = nb * 10 + (c - '0');
	if (sign == 1 && tmp > INT_MAX)
		return (1);
	if (sign == -1 && -tmp < INT_MIN)
		return (1);
	return (0);
}

int	ft_atoi_check(const char *str, int *error)
{
	long int	nb;
	int		sign;
	int		i;

	nb = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	if (!str[i])
		*error = 1;
	while (str[i])
	{
		if (!is_digit(str[i]) || check_overflow(nb, sign, str[i]))
		{
			*error = 1;
			return (0);
		}
		nb = nb * 10 + (str[i++] - '0');
	}
	return (nb * sign);
}
