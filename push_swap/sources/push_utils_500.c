/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils_500.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 19:32:12 by ichiro            #+#    #+#             */
/*   Updated: 2023/01/25 12:34:18 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	highest_index_stack(t_list **stack)
{
	int		i;
	int		j;
	t_list	*temp;

	i = 0;
	j = 0;
	temp = *stack;
	while (temp)
	{
		j = temp->index;
		if (j > i)
			i = j;
		temp = temp->next;
	}
	return (i);
}

int	push_b_rb(t_list **a, t_list **b, int j, int k)
{
	int	i;

	i = size_of(b);
	while (i < (*a)->divide[j])
	{
		if ((*a)->index < (*a)->divide[j])
		{
			pb(a, b);
			if ((*b)->index < (*a)->divide[k])
				rb(b);
			i++;
		}
		else
			ra(a);
	}
	return (i);
}

int	push_b_rb_split(t_list **a, t_list **b, int i, int j)
{
	int	k;

	k = j;
	while (i < (*a)->divide[j])
	{
		if ((*a)->index < (*a)->divide[k])
		{
			pb(a, b);
			if ((*b)->index < (*a)->divide[k] - ((*a)->divide[0] / 2))
				rb(b);
			i++;
		}
		else
			ra(a);
	}
	return (i);
}

int	fast_pa(t_list **a, t_list **b, int i, int j)
{
	int	fast;
	int	max;

	fast = 0;
	max = highest_index_stack(b);
	while (i > (*a)->divide[j])
	{
		if ((*b)->index == max)
		{
			pa(a, b);
			max--;
			i--;
		}
		else
		{
			fast = fastest_push(b, max);
			if (fast == 1)
				sb(b);
			else if (fast == 2)
				rb(b);
			else if (fast == 3)
				rrb(b);
		}
	}
	return (i);
}

int	fast_pa_tmp(t_list **a, t_list **b, int tmp)
{
	int	fast;
	int	max;

	fast = 0;
	max = highest_index_stack(b);
	while (tmp != 0)
	{
		if ((*b)->index == max)
		{
			pa(a, b);
			max--;
			tmp--;
		}
		else
		{
			fast = fastest_push(b, max);
			if (fast == 1)
				sb(b);
			else if (fast == 2)
				rb(b);
			else if (fast == 3)
				rrb(b);
		}
	}
	return (size_of(b));
}
