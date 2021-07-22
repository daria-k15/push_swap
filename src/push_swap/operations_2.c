#include "../../inc/push_swap.h"

int	rev_rotate(t_stack **stack, int flag)
{
	int		p;
	int		end;
	t_stack	*buf;

	buf = *stack;
	if (!buf || !buf->next)
		return (0);
	if (flag == 1)
		ft_putstr("rra\n");
	if (flag == 0)
		ft_putstr("rrb\n");
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

void	rrev_rotate(t_stack **a, t_stack **b)
{
	rev_rotate(a, -1);
	rev_rotate(b, -1);
	ft_putstr("rrr\n");
}

int	rotate(t_stack **stack, int flag)
{
	t_stack	*tmp;
	int		buf;
	int		start;

	if (!(*stack) || !(*stack)->next)
		return (0);
	if (flag == 1)
		ft_putstr("ra\n");
	if (flag == 0)
		ft_putstr("rb\n");
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

void	rrotate(t_stack **a, t_stack **b)
{
	rotate(a, -1);
	rotate(b, -1);
	ft_putstr("rr\n");
}
