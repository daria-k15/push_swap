#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/include/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack
{
	int				value;
	int				length;
	int				min;
	int				max;
	int				mid;
	int				*stack;
	struct s_stack	*next;
	struct s_stack	*prev;
}					t_stack;

void	sswap(t_stack **a, t_stack **b);
void	rrotate(t_stack **a, t_stack **b);
void	rrev_rotate(t_stack **a, t_stack **b);
int		swap(t_stack **stack, int flag);
int		rotate(t_stack **stack, int flag);
int		rev_rotate(t_stack **stack, int flag);
int		push(t_stack **a, t_stack **b, int flag);

void	sort_three(t_stack **a);
void	sort_five(t_stack **a, t_stack **b);

t_stack	*stackcpy(t_stack *a);
void	swap_elem(t_stack *stack, int a, int b);
int		mid(t_stack *a);

int		find_max(t_stack *a);
int		findmax_2(t_stack *a, int max);
int		find_min(t_stack *a);
int		index_max(t_stack *a);
int		last_v(t_stack *a);

int		is_previous(t_stack **a, t_stack **b, int sub, int main);
int		love_norm(t_stack *tmp, t_stack*buf, int main, int min);

int		is_sorted(t_stack **a);
int		is_sort(t_stack **a, t_stack **b);
int		stack_length(t_stack *lst);
int		is_duplicate(t_stack *a);
t_stack	*new_s(int num);
void	add_back(t_stack *lst, int value);

void	half_to_b(t_stack **a, t_stack **b);
void	kind_of_sel_sort(t_stack **a, t_stack **b);
void	half_to_a(t_stack **a, t_stack **b);
void	part_to_b(t_stack **a, t_stack **b, int div);
void	return_back(t_stack **a, t_stack **b);

void	free_s(t_stack **a);
void	min_init(t_stack *a);
void	max_init(t_stack *a);

void	error(void);
void	ft_putstr(char *s);
int		ft_atoi(const char *str);
int		not_num(const char *str);
t_stack	*stack_init(int length);

#endif
