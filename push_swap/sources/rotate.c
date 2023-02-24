/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:20:36 by ichiro            #+#    #+#             */
/*   Updated: 2022/11/25 22:57:46 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_list **stack)
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
	*stack = first->next;
	last->next = first;
	first->next = NULL;
	return ;
}

void	ra(t_list **stack_a)
{
	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	rotate_stack(stack_a);
	write(1, "ra\n", 3);
	return ;
}

void	rb(t_list **stack_b)
{
	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	rotate_stack(stack_b);
	write(1, "rb\n", 3);
	return ;
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (*stack_a == NULL || *stack_b == NULL || \
	(*stack_a)->next == NULL || (*stack_b)->next == NULL)
		return ;
	rotate_stack(stack_a);
	rotate_stack(stack_b);
	write(1, "rr\n", 3);
	return ;
}
