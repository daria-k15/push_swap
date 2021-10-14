/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:30:59 by heveline          #+#    #+#             */
/*   Updated: 2021/08/05 13:31:00 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

void	swap_ch(t_stack **stack)
{
	int	tmp;

	tmp = (*stack)->value;
	(*stack)->value = (*stack)->next->value;
	(*stack)->next->value = tmp;
}

void	sswap_ch(t_stack **a, t_stack **b)
{
	swap_ch(a);
	swap_ch(b);
}

int	push_ch(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	if (!(*b))
		return (0);
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
