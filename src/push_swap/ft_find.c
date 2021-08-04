#include "../../inc/push_swap.h"

int	find_max(t_stack *a)
{
	int	max;

	max = a->value;
	while (a)
	{
		if (a->value > max)
			max = a->value;
		a = a->next;
	}
	return (max);
}

int	findmax_2(t_stack *a, int max)
{
	int	max_2;

	max_2 = 0;
	while (a)
	{
		if (a->value < max && a->value > max_2)
			max_2 = a->value;
		a = a->next;
	}
	return (max_2);
}

int	find_min(t_stack *a)
{
	int	min;

	if (!a)
		return (0);
	min = a->value;
	while (a != NULL)
	{
		if (a->value < min)
			min = a->value;
		a = a->next;
	}
	return (min);
}

int	index_max(t_stack *a)
{
	int	max;
	int	i;

	max = find_max(a);
	i = 0;
	while (a->value != max)
	{
		i++;
		a = a->next;
	}
	return (i);
}

int	last_v(t_stack *a)
{
	if (a == 0)
		return (0);
	while (a->next)
		a = a->next;
	return (a->value);
}
