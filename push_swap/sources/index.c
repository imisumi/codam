/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 19:55:26 by ichiro            #+#    #+#             */
/*   Updated: 2023/01/25 12:36:16 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// finds the lowest number which has not been given an index yet
int	lowest_num(t_list **stack)
{
	t_list	*current;
	int		lowest;

	current = *stack;
	lowest = 0;
	while (current)
	{
		if (current->index == -1)
		{
			lowest = current->num;
			break ;
		}
		current = current->next;
	}
	while (current)
	{
		if (current->index == -1 && current->num < lowest)
			lowest = current->num;
		current = current->next;
	}
	return (lowest);
}

// sets the current index to the correspondent number
void	set_index(t_list *temp, int lowest, int i)
{
	while (temp)
	{
		if (temp->num == lowest)
		{
			set_group(temp, i);
			temp->index = i;
			break ;
		}
		temp = temp->next;
	}
}

// 100
void	num_index_100(t_list **stack, int argc)
{
	t_list	*current;
	t_list	*temp;
	int		lowest;
	int		i;

	i = 0;
	current = *stack;
	group(stack, argc);
	while (i <= argc - 2)
	{
		temp = current;
		lowest = lowest_num(stack);
		set_index(temp, lowest, i);
		if (current->index != -1)
			current = current->next;
		i++;
	}
}
