/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 13:29:23 by heveline          #+#    #+#             */
/*   Updated: 2021/08/05 13:29:32 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"
# include <unistd.h>
# include <stdlib.h>

void	swap_ch(t_stack **stack);
void	sswap_ch(t_stack **a, t_stack **b);
int		push_ch(t_stack **a, t_stack **b);
int		rev_rotate_ch(t_stack **stack);
void	rrev_rotate_ch(t_stack **a, t_stack **b);
int		rotate_ch(t_stack **stack);
void	rrotate_ch(t_stack **a, t_stack **b);

#endif
