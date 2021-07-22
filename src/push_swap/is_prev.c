#include "../../inc/push_swap.h"

/*
** is sub_number previous for main_number in two stacks?
*/
int	is_previous(t_stack **a, t_stack **b, int sub, int main)
{
	int		min;
	t_stack	*tmp;
	t_stack	*buf;

	tmp = *a;
	buf = *b;
	min = main - sub;
	if (min < 0)
		return (0);
	if (min == 1)
		return (1);
	return (love_norm(tmp, buf, main, min));
}

int	love_norm(t_stack *tmp, t_stack*buf, int main, int min)
{
	int	dif;

	while (tmp)
	{
		dif = main - tmp->value;
		if (dif > 0)
			if (dif < min)
				return (0);
		tmp = tmp->next;
	}
	while (buf)
	{
		dif = main - buf->value;
		if (dif > 0)
			if (dif < min)
				return (0);
		buf = buf->next;
	}
	return (1);
}
