#include "../../inc/checker.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str)
{
	size_t		i;
	int			sign;
	long long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		if (nb < -2147483647 && sign == -1)
			error();
		if (nb > 2147483647 && sign == 1)
			error();
		i++;
	}
	return (nb * sign);
}

int	not_num(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z'))
			return (1);
		i++;
	}
	return (0);
}

int	is_sort(t_stack **a, t_stack **b)
{
	t_stack	*a1;

	if (stack_length(*b))
		return (0);
	a1 = *a;
	while (a1->next != NULL)
	{
		if (a1->value > a1->next->value)
			return (0);
		a1 = a1->next;
	}
	return (1);
}
