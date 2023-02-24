/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:15:55 by ichiro            #+#    #+#             */
/*   Updated: 2023/01/25 12:58:51 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# include <string.h>

typedef struct s_list
{
	int				num;
	int				index;
	int				divide[32];
	int				group;
	struct s_list	*next;
	struct s_list	*previous;
}	t_list;

typedef struct s_data
{
	t_list	*stack_a;
	t_list	*stack_b;
}	t_data;

// SWAP
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);

// PUSH
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);

// ROTATE
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);

// REVERSE ROTATE
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);

// BIG STACK
void	stack_under_20(t_list **stack_a, t_list **stack_b);
void	big_stack(t_list **stack_a, t_list **stack_b, int argc);
void	test_500(t_list **a, t_list **b);

// GROUP
void	set_group(t_list *stack, int index);
void	group_div(t_list *current, int x, int y);
void	group(t_list **stack, int argc);

// INDEX
int		lowest_num(t_list **stack);
void	set_index(t_list *temp, int lowest, int i);
void	num_index_100(t_list **stack, int argc);

// MAIN
void	error_alarm(char *str);

// NEW NODE
void	new_node(t_list **stack_a, int number);

// PUSH UTILS 1
int		size_of(t_list **stack);
int		rotate_count(t_list **stack, int size, int index);
int		reverse_rotate_count(t_list **stack, int size, int index);
int		fastest_push(t_list **stack, int index);
void	last_three(t_list **stack);

// PUSH UTILS 2
int		check_sorted_a(t_list **stack_a);
int		check_sorted_b(t_list **stack_b);
void	set_previous(t_list **stack);
int		rotate_count_group(t_list **stack, int size, int group);
int		reverse_rotate_count_group(t_list **stack, int size, int index);

// PUSH UTILS 3
int		fastest_push_group(t_list **stack, int group);
void	sort_final(t_list **stack_a, t_list **stack_b);
int		first_push_b(t_list **a, t_list **b, int g);
void	seccond_push_b(t_list **a, t_list **b, int i, int g);
int		sort_min_3(t_list **a, t_list **b, int i);

// PUSH UTILS 4
int		split_500_1(t_list **a, t_list **b);
int		split_500_2(t_list **a, t_list **b, int i);
int		split_500_3(t_list **a, t_list **b, int i);
int		split_500_4(t_list **a, t_list **b, int i, int max);

// PUSH UTILS 5
int		split_500_5(t_list **a, t_list **b, int i);
int		split_500_6(t_list **a, t_list **b, int i);
int		split_500_7(t_list **a, t_list **b, int i, int tmp);
void	split_500_8(t_list **a, t_list **b, int i, int tmp);

// PUSH UTILS 500
int		highest_index_stack(t_list **stack);
int		push_b_rb(t_list **a, t_list **b, int j, int k);
int		push_b_rb_split(t_list **a, t_list **b, int i, int j);
int		fast_pa(t_list **a, t_list **b, int i, int j);
int		fast_pa_tmp(t_list **a, t_list **b, int tmp);

// PUSH UTILS 501
void	last_chunk_one(t_list **a, t_list **b);
void	last_chunk_two(t_list **a, t_list **b, int tmp, int tmp2);

// SMALL STACK
void	small_stack(t_list **stack_a, t_list **stack_b, int argc);

// void	print_stacks(t_list **stack_a, t_list **stack_b);
// void	test_500(t_list **a, t_list **b);

#endif