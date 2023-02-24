/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:01:42 by ichiro            #+#    #+#             */
/*   Updated: 2022/12/28 22:11:20 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// return the size of a linked-list
int	size_of(t_list **stack)
{
	int		i;
	t_list	*current;

	current = *stack;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}

// count how many moves it will take to put index at the
// top of stack using rotate
int	rotate_count(t_list **stack, int size, int index)
{
	t_list	*current;
	int		r_count;

	r_count = 0;
	current = *stack;
	while (r_count < size)
	{
		if (current->index == index)
			break ;
		r_count++;
		current = current->next;
	}
	return (r_count);
}

// count how many moves it will take to put index at the top
// of stack using reverse rotate
int	reverse_rotate_count(t_list **stack, int size, int index)
{
	t_list	*current;
	int		rr_count;

	rr_count = 0;
	current = *stack;
	while (rr_count < size)
	{
		if (current->index == index)
			break ;
		rr_count++;
		current = current->previous;
	}
	return (rr_count);
}

int	fastest_push(t_list **stack, int index)
{
	int		ra;
	int		rra;
	int		size;

	ra = 0;
	rra = 0;
	set_previous(stack);
	size = size_of(stack);
	ra = rotate_count(stack, size, index);
	rra = reverse_rotate_count(stack, size, index);
	if (ra == 1)
		return (1);
	if (ra <= rra)
		return (2);
	return (3);
}

// sorts the last 3 numbers in stack a
void	last_three(t_list **stack)
{
	t_list	*current;
	int		max;

	max = 0;
	current = *stack;
	while (current)
	{
		if (max < current->index)
			max = current->index;
		current = current->next;
	}
	if ((*stack)->index == max)
		ra(stack);
	if ((*stack)->next->index == max)
		rra(stack);
	if ((*stack)->index == max - 1)
		sa(stack);
}
