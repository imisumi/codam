/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:49:57 by imisumi           #+#    #+#             */
/*   Updated: 2023/01/23 08:48:01 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// checks if a is sorted
int	check_sorted_a(t_list **stack_a)
{
	t_list	*current;
	int		last;

	current = *stack_a;
	while (current->next != NULL)
	{
		if (current->index > current->next->index)
			return (1);
		current = current->next;
	}
	return (0);
}

// checks if b is sorted
int	check_sorted_b(t_list **stack_b)
{
	t_list	*current;
	int		last;

	current = *stack_b;
	while (current->next != NULL)
	{
		if (current->index < current->next->index)
			return (1);
		current = current->next;
	}
	return (0);
}

// sets the previous pointer in the linked-list to the last node
void	set_previous(t_list **stack)
{
	t_list	*current;
	t_list	*prev;

	current = *stack;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
		current->previous = prev;
	}
	(*stack)->previous = current;
}

// count how many moves it will take to put group at the
// top of stack using rotate
int	rotate_count_group(t_list **stack, int size, int group)
{
	t_list	*current;
	int		r_count;

	r_count = 0;
	current = *stack;
	while (r_count < size)
	{
		if (current->group == group)
			break ;
		r_count++;
		current = current->next;
	}
	return (r_count);
}

// count how many moves it will take to put group at the top
// of stack using reverse rotate
int	reverse_rotate_group(t_list **stack, int size, int group)
{
	t_list	*current;
	int		rr_count;

	rr_count = 0;
	current = *stack;
	while (rr_count < size)
	{
		if (current->group == group)
			break ;
		rr_count++;
		current = current->previous;
	}
	return (rr_count);
}
