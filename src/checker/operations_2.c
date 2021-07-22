#include "../../inc/checker.h"

int	rev_rotate_ch(t_stack **stack)
{
	int		p;
	int		end;
	t_stack	*buf;

	buf = *stack;
	if (!buf || !buf->next)
		return (0);
	while (buf->next != NULL)
		buf = buf->next;
	end = buf->value;
	while (buf->prev != NULL)
	{
		p = buf->value;
		buf->value = buf->prev->value;
		buf->prev->value = p;
		buf = buf->prev;
	}
	buf->value = end;
	return (1);
}

void	rrev_rotate_ch(t_stack **a, t_stack **b)
{
	rev_rotate_ch(a);
	rev_rotate_ch(b);
}

int	rotate_ch(t_stack **stack)
{
	t_stack	*tmp;
	int		buf;
	int		start;

	if (!(*stack) || !(*stack)->next)
		return (0);
	tmp = *stack;
	start = tmp->value;
	while (tmp->next != NULL)
	{
		buf = tmp->value;
		tmp->value = tmp->next->value;
		tmp->next->value = buf;
		tmp = tmp->next;
	}
	tmp->value = start;
	return (1);
}

void	rrotate_ch(t_stack **a, t_stack **b)
{
	rotate_ch(a);
	rotate_ch(b);
}
