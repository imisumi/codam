/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 00:20:06 by ichiro            #+#    #+#             */
/*   Updated: 2022/11/25 22:58:53 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*sec;
	t_list	*temp;

	if (*stack_a == NULL || (*stack_a)->next == NULL)
		return ;
	first = *stack_a;
	sec = first->next;
	temp = sec->next;
	*stack_a = sec;
	sec->next = first;
	first->next = temp;
	write(1, "sa\n", 3);
	return ;
}

void	sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*sec;
	t_list	*temp;

	if (*stack_b == NULL || (*stack_b)->next == NULL)
		return ;
	first = *stack_b;
	sec = first->next;
	temp = sec->next;
	*stack_b = sec;
	sec->next = first;
	first->next = temp;
	write(1, "sb\n", 3);
	return ;
}
