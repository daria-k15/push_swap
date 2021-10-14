/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:32:47 by heveline          #+#    #+#             */
/*   Updated: 2021/08/05 15:54:09 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/push_swap.h"

t_stack	*arg_initial(int argc, char **argv)
{
	long long	num;
	t_stack		*a;
	int			i;

	i = 1;
	a = NULL;
	while (i < argc)
	{
		if (not_num(argv[i]))
			error();
		num = ft_atoi_n(argv[i]);
		if (i == 1)
			a = new_s(num);
		else
			add_back(a, num);
		i++;
	}
	return (a);
}

void	return_back(t_stack **a, t_stack **b)
{
	int	div;

	if (stack_length(*b) == 0)
		return ;
	div = (*a)->value;
	half_to_a(a, b);
	while ((is_previous(a, b, last_v(*a), (*a)->value) || \
				((*a)->value == (*a)->min && !is_sort(a, b))))
		rotate(a, 1);
	return_back(a, b);
	part_to_b(a, b, div);
}

void	sorting(t_stack *a, t_stack *b)
{
	half_to_b(&a, &b);
	return_back(&a, &b);
	part_to_b(&a, &b, a->min);
}

int	push_swap(t_stack *a, t_stack *b)

{
	if (is_duplicate(a))
		error();
	if (is_sort(&a, &b))
		return (0);
	if (stack_length(a) == 3)
		sort_three(&a);
	else if (stack_length(a) == 4)
		sort_four(&a, &b);
	else if (stack_length(a) == 5)
		sort_five(&a, &b);
	else
		sorting(a, b);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc > 1)
	{
		a = arg_initial(argc, argv);
		min_init(a);
		max_init(a);
		push_swap(a, b);
		free_s(&a);
	}
	return (0);
}
