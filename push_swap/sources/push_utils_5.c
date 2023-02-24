/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 22:03:34 by ichiro            #+#    #+#             */
/*   Updated: 2023/01/23 08:49:58 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	split_500_5(t_list **a, t_list **b, int i)
{
	int	tmp;

	tmp = 0;
	while ((*a)->group < 7)
	{
		if ((*a)->index < (*a)->divide[4] + ((*a)->divide[0] / 4))
			ra(a);
		else
		{
			pb(a, b);
			if ((*b)->index < (*a)->divide[4] + ((*a)->divide[0] / 2) \
			+ ((*a)->divide[0] / 8))
				rb(b);
			i++;
			tmp++;
		}
	}
	i = fast_pa_tmp(a, b, tmp);
	set_previous(a);
	return (i);
}

int	split_500_6(t_list **a, t_list **b, int i)
{
	int	tmp;
	int	tmp2;

	tmp = 0;
	tmp2 = 0;
	while ((*a)->previous->group < 7)
	{
		rrr(a, b);
		tmp++;
	}
	tmp2 = tmp;
	while (tmp != 0)
	{
		pb(a, b);
		if ((*b)->index < (*a)->divide[3] + ((*a)->divide[0] / 2) \
		+ ((*a)->divide[0] / 3))
			rb(b);
		tmp--;
		i++;
	}
	i = fast_pa_tmp(a, b, tmp2);
	i = fast_pa(a, b, i, 2);
	return (i);
}

int	split_500_7(t_list **a, t_list **b, int i, int tmp)
{
	while (i - 1 > (*a)->divide[0] + ((*a)->divide[0] / 2))
	{
		if ((*b)->index > (*a)->divide[0] + ((*a)->divide[0] / 2))
		{
			pa(a, b);
			i--;
		}
		else
			rb(b);
	}
	while ((*a)->group < 4)
	{
		if ((*a)->index > (*a)->divide[1] + ((*a)->divide[0] / 4))
		{
			pb(a, b);
			if ((*b)->index < (*a)->divide[1] + ((*a)->divide[0] / 2) \
			+ ((*a)->divide[0] / 8))
				rb(b);
			i++;
			tmp++;
		}
		else
			ra(a);
	}
	return (i);
}

void	split_500_8(t_list **a, t_list **b, int i, int tmp)
{
	int	tmp2;

	tmp2 = 0;
	i = fast_pa_tmp(a, b, tmp);
	set_previous(a);
	while ((*a)->previous->group < 4)
	{
		rra(a);
		tmp++;
	}
	while (tmp != 0)
	{
		pb(a, b);
		if ((*b)->index < (*a)->divide[1] - ((*a)->divide[0] / 8))
			rb(b);
		i++;
		tmp--;
		tmp2++;
	}
	i = fast_pa_tmp(a, b, tmp2);
	last_chunk_one(a, b);
}
