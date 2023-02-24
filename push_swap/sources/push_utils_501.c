/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils_501.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 21:24:02 by ichiro            #+#    #+#             */
/*   Updated: 2023/01/25 12:07:20 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	last_chunk_one(t_list **a, t_list **b)
{
	int	tmp;
	int	tmp2;
	int	size;
	int	i;

	tmp = 0;
	tmp2 = 0;
	size = size_of(b);
	i = size;
	while (i != 0)
	{
		if ((*b)->index > (size / 2))
		{
			pa(a, b);
			tmp++;
		}
		else
			rb(b);
		i--;
	}
	last_chunk_two(a, b, tmp, tmp2);
}

void	last_chunk_two(t_list **a, t_list **b, int tmp, int tmp2)
{
	int	i;

	while (*b)
	{
		pa(a, b);
		tmp2++;
	}
	i = tmp2;
	while (i != 0)
	{
		pb(a, b);
		if ((*b)->index < tmp2 / 2)
			rb(b);
		i--;
	}
	i = tmp;
	while (i != 0)
	{
		pb(a, b);
		if ((*b)->index < tmp2 + (tmp / 2))
			rb(b);
		i--;
	}
	sort_final(a, b);
	exit(0);
}
