#include "../../inc/push_swap.h"

t_stack	*stackcpy(t_stack *a)
{
	int		i;
	t_stack	*b;

	i = 0;
	b = stack_init(stack_length(a));
	while (a != NULL)
	{
		b->stack[i] = (a)->value;
		(a) = (a)->next;
		i++;
	}
	return (b);
}

void	swap_elem(t_stack *stack, int a, int b)
{
	int	tmp;

	tmp = stack->stack[a];
	stack->stack[a] = stack->stack[b];
	stack->stack[b] = tmp;
}

int	mid(t_stack *a)
{
	int		i;
	int		j;
	t_stack	*b;
	int		lowest_value_index;
	int		mid;

	i = 0;
	b = stackcpy(a);
	while (i <= b->length / 2)
	{
		lowest_value_index = i;
		j = i;
		while (++j < b->length)
			if (b->stack[j] < b->stack[lowest_value_index])
				lowest_value_index = j;
		swap_elem(b, i, lowest_value_index);
		i++;
	}
	mid = b->stack[i - 1];
	free(b->stack);
	free(b);
	return (mid);
}
