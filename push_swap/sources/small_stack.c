/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:13:02 by ichiro            #+#    #+#             */
/*   Updated: 2022/11/25 23:08:29 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_two(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	if (current->index > current->next->index)
		sa(stack_a);
}

static void	sort_three(t_list **stack_a)
{
	t_list	*current;

	current = *stack_a;
	if (current->index == 2)
	{
		if (current->next->index == 0)
			return (ra(stack_a));
		ra(stack_a);
		sa(stack_a);
	}
	else if (current->index == 1)
	{
		if (current->next->index == 0)
			return (sa(stack_a));
		rra(stack_a);
	}
	else if (current->next->index == 2)
	{
		ra(stack_a);
		sa(stack_a);
		rra(stack_a);
	}
}

static void	sort_four(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	current = *stack_a;
	if (current->next->next->next->index == 3)
		rra(stack_a);
	else if (current->next->next->index == 3)
	{
		ra(stack_a);
		ra(stack_a);
	}
	else if (current->next->index == 3)
		sa(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	ra(stack_a);
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	t_list	*current;

	current = *stack_a;
	if (current->next->next->next->next->index == 4)
		rra(stack_a);
	else if (current->next->next->next->index == 4)
	{
		rra(stack_a);
		rra(stack_a);
	}
	else if (current->next->next->index == 4)
	{
		ra(stack_a);
		ra(stack_a);
	}
	if (current->next->index == 4)
		sa(stack_a);
	pb(stack_a, stack_b);
	sort_four(stack_a, stack_b);
	pa(stack_a, stack_b);
	ra(stack_a);
}

void	small_stack(t_list **stack_a, t_list **stack_b, int argc)
{
	int	numbers;

	numbers = argc - 1;
	if (numbers == 2)
		sort_two(stack_a);
	if (numbers == 3)
		sort_three(stack_a);
	if (numbers == 4)
		sort_four(stack_a, stack_b);
	if (numbers == 5)
		sort_five(stack_a, stack_b);
	return ;
}
