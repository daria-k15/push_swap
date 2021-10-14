/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:33:17 by heveline          #+#    #+#             */
/*   Updated: 2021/08/05 13:33:19 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	half_to_b(t_stack **a, t_stack **b)
{
	int	mid_v;

	mid_v = mid(*a);
	while ((stack_length(*a) - stack_length(*b) > 1) && stack_length(*a) > 3)
	{
		if ((*a)->value < mid_v)
			push(b, a, 1);
		else
			rotate(a, 1);
	}
	if (stack_length(*a) == 3)
		sort_three(a);
}

void	kind_of_sel_sort(t_stack **a, t_stack **b)
{
	int	index;

	index = index_max(*b);
	if ((*b)->value == find_max(*b))
		push(a, b, 0);
	else if (is_previous(a, b, last_v(*a), (*b)->value) \
		      || (*b)->value == (*a)->min)
	{
		push(a, b, 0);
		rotate(a, 1);
	}
	else if (index <= stack_length(*b) - index)
		rotate(b, 0);
	else
		rev_rotate(b, 0);
}

void	half_to_a(t_stack **a, t_stack **b)
{
	int	mid_v;
	int	i;

	mid_v = mid(*b);
	i = stack_length(*b);
	while (i >= 0 && (*b))
	{
		if (stack_length(*b) < 13)
			kind_of_sel_sort(a, b);
		else if ((*b)->value >= mid_v)
			push(a, b, 0);
		else if (is_previous(a, b, last_v(*a), (*b)->value) \
				|| (*b)->value == (*a)->min)
		{
			push(a, b, 0);
			rotate(a, 1);
		}
		else
			rotate(b, 0);
		i--;
	}
}

void	part_to_b(t_stack **a, t_stack **b, int div)
{
	if (div != (*a)->min && div <= last_v(*a))
		return ;
	while ((*a)->value != div)
	{
		if (is_previous(a, b, last_v(*a), (*a)->value))
			rotate(a, 1);
		else
			push(b, a, 1);
	}
	if (is_previous(a, b, last_v(*a), find_min(*b)))
		return_back(a, b);
}
