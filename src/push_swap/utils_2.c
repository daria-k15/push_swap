/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:33:49 by heveline          #+#    #+#             */
/*   Updated: 2021/08/05 13:33:51 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

void	free_s(t_stack **a)
{
	t_stack	*tmp;

	if (!(*a))
		return ;
	while (*a != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		free(tmp);
	}
}

void	min_init(t_stack *a)
{
	int	min;

	min = find_min(a);
	while (a)
	{
		a->min = min;
		a = a->next;
	}
}

void	max_init(t_stack *a)
{
	int	max;

	max = find_max(a);
	while (a)
	{
		a->max = max;
		a = a->next;
	}
}
