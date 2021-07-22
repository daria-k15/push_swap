#include "../../inc/push_swap.h"

void	add_back(t_stack *lst, int value)
{
	t_stack	*last;
	t_stack	*tmp;

	tmp = (t_stack *)malloc(sizeof(t_stack));
	while (lst->next != NULL)
		lst = lst->next;
	last = lst;
	tmp->value = value;
	tmp->next = NULL;
	last->next = tmp;
	tmp->prev = last;
}

t_stack	*new_s(int num)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->value = num;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

int	stack_length(t_stack *lst)
{
	int	len;

	len = 0;
	if (!lst)
		return (0);
	while (lst)
	{
		lst = lst->next;
		len++;
	}
	return (len);
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

int	is_duplicate(t_stack *a)
{
	t_stack	*tmp;

	while (a->next != NULL)
	{
		tmp = a;
		while (tmp->next != NULL)
		{
			if (tmp->next->value == a->value)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
