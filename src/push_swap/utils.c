#include "../../inc/push_swap.h"

void	error(void)
{
	write(1, "Error\n", 6);
	exit(1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
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

t_stack	*stack_init(int length)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->stack = (int *)malloc(sizeof(int) * length);
	if (!stack->stack)
		return (NULL);
	stack->length = length;
	return (stack);
}
