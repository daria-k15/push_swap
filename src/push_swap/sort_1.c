/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:33:10 by heveline          #+#    #+#             */
/*   Updated: 2021/08/05 13:36:12 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	sort_three(t_stack **a)
{
	while (!is_sorted(a))
	{
		if ((*a)->next->next->value > (*a)->next->value
			&& (*a)->next->next->value < (*a)->value
			&& (*a)->value > (*a)->next->value)
			rotate(a, 1);
		else if ((*a)->next->next->value < (*a)->next->value
			&& (*a)->next->next->value < (*a)->value
			&& (*a)->next->value > (*a)->value)
			rev_rotate(a, 1);
		else if (((*a)->next->value > (*a)->value
				|| (*a)->next->value < (*a)->value))
			swap(a, 1);
	}
}

void	sort_four(t_stack **a, t_stack **b)
{
	while (stack_length(*a) > 3)
	{
		if ((*a)->value == (*a)->max)
			push(b, a, 1);
		else
			rotate (a, 1);
	}
	sort_three(a);
	while (*b != NULL)
	{
		push(a, b, 0);
		if ((*a)->value > (*a)->next->value && (*a)->value > last_v(*a))
			rotate(a, 1);
		else if ((*a)->value > (*a)->next->value)
			swap(a, 1);
	}
}

void	sort_five(t_stack **a, t_stack **b)
{
	while (stack_length(*a) != 3)
	{
		if ((*a)->value == (*a)->max || (*a)->value == (*a)->min)
			push(b, a, 1);
		else
			rotate (a, 1);
	}
	sort_three(a);
	if ((*b)->value > (*b)->next->value)
		swap(b, 0);
	while ((*b) != NULL)
	{
		push(a, b, 0);
		if ((*a)->value > (*a)->next->value && (*a)->value > last_v(*a))
			rotate(a, 1);
		else if ((*a)->value > (*a)->next->value)
			swap(a, 1);
	}
}

int	is_sorted(t_stack **a)
{
	t_stack	*a1;

	a1 = *a;
	while (a1->next != NULL)
	{
		if (a1->value > a1->next->value)
			return (0);
		a1 = a1->next;
	}
	return (1);
}
