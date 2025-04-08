#include"push_swap.h"

static int	is_space(char c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}

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
	while (is_space(str[i]))
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