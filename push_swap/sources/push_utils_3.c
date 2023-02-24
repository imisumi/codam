/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:03:34 by ichiro            #+#    #+#             */
/*   Updated: 2023/01/31 17:51:32 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fastest_push_group(t_list **stack, int group)
{
	int		ra;
	int		rra;
	int		size;

	ra = 0;
	rra = 0;
	set_previous(stack);
	size = size_of(stack);
	ra = rotate_count(stack, size, group);
	rra = reverse_rotate_count(stack, size, group);
	if (ra == 1)
		return (1);
	if (ra <= rra)
		return (2);
	return (3);
}

// pushes b to a in the correct sorted order
void	sort_final(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	fast;

	max = 0;
	fast = 0;
	max = size_of(stack_b) - 1;
	while (*stack_b)
	{
		if ((*stack_b)->index == max)
		{
			pa(stack_a, stack_b);
			max--;
		}
		else
		{
			fast = fastest_push(stack_b, max);
			if (fast == 1)
				sb(stack_b);
			else if (fast == 2)
				rb(stack_b);
			else if (fast == 3)
				rrb(stack_b);
		}
	}
}

int	first_push_b(t_list **a, t_list **b, int g)
{
	int	group;
	int	i;

	group = 1;
	i = 0;
	while (i < (*a)->divide[g - 1])
	{
		if ((*a)->group == group && (*a)->index != (*a)->divide[g] - 1 && \
		(*a)->index < (*a)->divide[g] - 2 && (*a)->index != (*a)->divide[g] - 3)
		{
			pb(a, b);
			if ((*b)->index < ((*a)->divide[group - 1] - ((*a)->divide[0] / 2)))
				rb(b);
			i++;
		}
		else
			ra(a);
		if (i == (*a)->divide[group - 1])
			group++;
	}
	return (i);
}

void	seccond_push_b(t_list **a, t_list **b, int i, int g)
{
	int	fast;

	fast = 0;
	while ((i + 3) < (*a)->divide[g])
	{
		if ((*a)->index == i)
		{
			pb(a, b);
			i++;
		}
		else
		{
			fast = fastest_push(a, i);
			if (fast == 1)
				sa(a);
			else if (fast == 2)
				ra(a);
			else if (fast == 3)
				rra(a);
		}
	}
}

int	sort_min_3(t_list **a, t_list **b, int i)
{
	int	fast;

	fast = 0;
	while ((i + 3) < (*a)->divide[11])
	{
		if ((*a)->index == i)
		{
			pb(a, b);
			i++;
		}
		else
		{
			fast = fastest_push(a, i);
			if (fast == 1)
				sa(a);
			else if (fast == 2)
				ra(a);
			else if (fast == 3)
				rra(a);
		}
	}
	last_three(a);
	return (i);
}
