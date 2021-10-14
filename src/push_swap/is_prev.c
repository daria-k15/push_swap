/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_prev.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:32:12 by heveline          #+#    #+#             */
/*   Updated: 2021/08/05 13:32:17 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

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
