/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:30:48 by heveline          #+#    #+#             */
/*   Updated: 2021/08/05 13:30:52 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/checker.h"

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

void	norm_avoiding(t_stack **a, t_stack **b, char *line)
{
	if (!ft_strcmp("ra", line))
		rotate_ch(a);
	else if (!ft_strcmp("rb", line))
		rotate_ch(b);
	else if (!ft_strcmp("rr", line))
		rrotate_ch(a, b);
	else if (!ft_strcmp("rra", line))
		rev_rotate_ch(a);
	else if (!ft_strcmp("rrb", line))
		rev_rotate_ch(b);
	else if (!ft_strcmp("rrr", line))
		rrev_rotate_ch(a, b);
}

void	checker(t_stack **a, t_stack **b)
{
	char	*line;

	while (get_next_line(0, &line))
	{
		if (*line == 'r')
			norm_avoiding(a, b, line);
		else if (!ft_strcmp("sa", line))
			swap_ch(a);
		else if (!ft_strcmp("sb", line))
			swap_ch(b);
		else if (!ft_strcmp("ss", line))
			sswap_ch(a, b);
		else if (!ft_strcmp("pa", line))
			push_ch(a, b);
		else if (!ft_strcmp("pb", line))
			push_ch(b, a);
		else if (!ft_strcmp("", line))
			break ;
		else
			error();
		free(line);
	}
	free(line);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	b = NULL;
	if (argc > 1)
	{
		a = arg_initial(argc, argv);
		if (is_duplicate(a))
			error();
		checker(&a, &b);
		if (is_sort(&a, &b))
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
		free_s(&a);
	}
}
