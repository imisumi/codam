/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:25:10 by ichiro            #+#    #+#             */
/*   Updated: 2022/12/07 18:18:01 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_stack(t_list **stack)
{
	t_list	*first;
	t_list	*last;
	t_list	*prev;

	first = *stack;
	last = *stack;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
		last->previous = prev;
	}
	*stack = last;
	last->next = first;
	prev->next = NULL;
	return ;
}

void	rra(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	reverse_rotate_stack(stack_a);
	write(1, "rra\n", 4);
	return ;
}

void	rrb(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	reverse_rotate_stack(stack_b);
	write(1, "rrb\n", 4);
	return ;
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL || \
	(*stack_a)->next == NULL || (*stack_b)->next == NULL)
		return ;
	reverse_rotate_stack(stack_a);
	reverse_rotate_stack(stack_b);
	write(1, "rrr\n", 4);
	return ;
}
