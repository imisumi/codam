/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 19:29:45 by ichiro            #+#    #+#             */
/*   Updated: 2023/01/25 13:06:16 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_group(t_list *stack, int index)
{
	if (index < stack->divide[0])
		stack->group = 1;
	else if (index < stack->divide[1])
		stack->group = 2;
	else if (index < stack->divide[2])
		stack->group = 3;
	else if (index < stack->divide[3])
		stack->group = 4;
	else if (index < stack->divide[4])
		stack->group = 5;
	else if (index < stack->divide[5])
		stack->group = 6;
	else if (index < stack->divide[6])
		stack->group = 7;
	else if (index < stack->divide[7])
		stack->group = 8;
	else if (index < stack->divide[8])
		stack->group = 9;
	else if (index < stack->divide[9])
		stack->group = 10;
	else if (index < stack->divide[10])
		stack->group = 11;
	else if (index < stack->divide[11])
		stack->group = 12;
}

void	group_div(t_list *current, int x, int y)
{
	int	i;

	i = 0;
	while (i < (x % y))
	{
		if (i != 0)
			current->divide[i] = (x / y) + 1 + current->divide[i - 1];
		else
			current->divide[i] = (x / y) + 1;
		i++;
	}
	while (i < y)
	{
		if (i != 0)
			current->divide[i] = (x / y) + current->divide[i - 1];
		else
			current->divide[i] = (x / y);
		i++;
	}
}

void	group(t_list **stack, int argc)
{
	t_list	*current;
	int		x;
	int		y;

	if (argc < 200)
		y = 4;
	else
		y = 12;
	x = argc - 1;
	current = *stack;
	while (current)
	{
		group_div(current, x, y);
		current = current->next;
	}
}
