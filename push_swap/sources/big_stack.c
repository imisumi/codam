/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 02:03:49 by ichiro            #+#    #+#             */
/*   Updated: 2023/01/25 13:12:08 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// sort stack under 20 numbers
void	stack_under_20(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->next != NULL)
	{
		if ((*stack_a)->index != (*stack_a)->divide[3] - 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
	}
	sort_final(stack_a, stack_b);
	exit(0);
}

void	big_stack(t_list **a, t_list **b, int argc)
{
	int	i;
	int	g;

	g = 0;
	i = 0;
	if (argc < 20)
		stack_under_20(a, b);
	if (argc < 200)
		g = 3;
	else
		g = 11;
	if (argc > 300)
		test_500(a, b);
	i = first_push_b(a, b, g);
	seccond_push_b(a, b, i, g);
	last_three(a);
	sort_final(a, b);
}

void	test_500(t_list **a, t_list **b)
{
	int	i;
	int	max;
	int	tmp;

	i = 0;
	max = 0;
	tmp = 0;
	i = push_b_rb(a, b, 5, 2);
	i = push_b_rb(a, b, 9, 7);
	i = push_b_rb_split(a, b, i, 10);
	i = sort_min_3(a, b, i);
	max = 0;
	i = fast_pa(a, b, i, 9);
	i = split_500_1(a, b);
	i = split_500_2(a, b, i);
	max = i - 1;
	i = split_500_3(a, b, i);
	i = split_500_4(a, b, i, max);
	i = split_500_5(a, b, i);
	i = split_500_6(a, b, i);
	i = split_500_7(a, b, i, 0);
	split_500_8(a, b, i, tmp);
}
