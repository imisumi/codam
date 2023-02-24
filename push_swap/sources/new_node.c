/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_node.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 19:00:44 by ichiro            #+#    #+#             */
/*   Updated: 2023/01/25 13:02:55 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	insert_end(t_list **stack_a, t_list *new_node, int number)
{
	t_list	*current;

	current = *stack_a;
	while (current->next != NULL)
	{
		if (number == current->num)
			error_alarm("Error\n");
		current = current->next;
	}
	if (number == current->num)
		error_alarm("Error\n");
	current->next = new_node;
}

void	new_node(t_list **stack_a, int number)
{
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	if (!new_node)
		exit(1);
	new_node->num = number;
	new_node->index = -1;
	new_node->next = NULL;
	if (*stack_a == NULL)
	{
		*stack_a = new_node;
		return ;
	}
	insert_end(stack_a, new_node, number);
}
