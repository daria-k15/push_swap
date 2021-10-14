/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:32:23 by heveline          #+#    #+#             */
/*   Updated: 2021/08/05 13:32:25 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

int	swap(t_stack **stack, int flag)
{
	int	tmp;

	if (flag == 1)
		ft_putstr("sa\n");
	if (flag == 0)
		ft_putstr("sb\n");
	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
	return (1);
}

void	sswap(t_stack **a, t_stack **b)
{
	swap(a, -1);
	swap(b, -1);
	ft_putstr("ss\n");
}

int	push(t_stack **a, t_stack **b, int flag)
{
	t_stack	*tmp;

	if (!(*b))
		return (0);
	if (flag == 1)
		ft_putstr("pb\n");
	else
		ft_putstr("pa\n");
	tmp = *b;
	*b = (*b)->next;
	if (*b != NULL)
		(*b)->prev = NULL;
	tmp->next = *a;
	if (*a != NULL)
		(*a)->prev = tmp;
	*a = tmp;
	return (1);
}
