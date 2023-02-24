/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils_4.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:03:34 by ichiro            #+#    #+#             */
/*   Updated: 2023/01/23 08:48:24 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_500_1(t_list **a, t_list **b)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = 0;
	while ((*b)->group > 8)
		pa(a, b);
	i = size_of(b);
	tmp = i;
	while (tmp < (*a)->divide[9])
	{
		if ((*a)->index < (*a)->divide[8])
			ra(a);
		else
		{
			pb(a, b);
			if ((*b)->index < (*a)->divide[8] + ((*a)->divide[0] / 2))
				rb(b);
			i++;
		}
		tmp++;
	}
	return (i);
}

int	split_500_2(t_list **a, t_list **b, int i)
{
	i = fast_pa(a, b, i, 7);
	set_previous(a);
	while ((*a)->previous->group == 9)
		rrr(a, b);
	while ((*a)->group == 9)
	{
		pb(a, b);
		if ((*b)->index < (*a)->divide[7] + ((*a)->divide[0] / 2))
			rb(b);
		i++;
	}
	i = fast_pa(a, b, i, 7);
	set_previous(b);
	while ((*b)->previous->group > 6)
		rrb(b);
	return (i);
}

int	split_500_3(t_list **a, t_list **b, int i)
{
	while ((*b)->group > 6)
	{
		pa(a, b);
		if ((*a)->group == 7)
			ra(a);
	}
	while ((*a)->group == 8)
	{
		pb(a, b);
		if ((*b)->index < (*a)->divide[6] + ((*a)->divide[0] / 2))
			rb(b);
	}
	i = size_of(b);
	i = fast_pa(a, b, i, 5);
	i = size_of(b);
	set_previous(a);
	while ((*a)->previous->group == 7)
		rra(a);
	return (i);
}

int	split_500_4(t_list **a, t_list **b, int i, int max)
{
	while ((*a)->group == 7)
	{
		pb(a, b);
		if ((*b)->index < (*a)->divide[5] + ((*a)->divide[0] / 2))
			rb(b);
		i++;
	}
	max = highest_index_stack(b);
	i = fast_pa(a, b, i, 5);
	max = highest_index_stack(b);
	while ((*b)->group > 3)
	{
		if ((*b)->index < (*a)->divide[3] + ((*a)->divide[0] / 2))
			rb(b);
		else
		{
			pa(a, b);
			i--;
		}
	}
	return (i);
}
