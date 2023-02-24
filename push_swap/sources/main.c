/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:45:45 by ichiro            #+#    #+#             */
/*   Updated: 2023/01/25 12:58:50 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// error meseage
void	error_alarm(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i])
		{
			write (1, &str[i], 1);
			i++;
		}
	}
	exit(1);
}

// ascii to integer
int	ft_atoi(const char *nptr)
{
	int			i;
	int			neg;
	long long	res;

	i = 0;
	res = 0;
	neg = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
		neg = -1;
	if (nptr[i] == '-' || nptr[i] == '+')
		i++;
	while (nptr[i])
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
			res = res * 10 + nptr[i] - 48;
		else
			error_alarm("Error\n");
		i++;
	}
	res = res * neg;
	if (res > 2147483647 || res < -2147483648)
		error_alarm("Error\n");
	return (res);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	int		i;
	int		j;
	int		check;
	int		prev_num;

	data.stack_a = NULL;
	data.stack_b = NULL;
	i = 1;
	if (argc <= 1)
		exit(0);
	while (i < argc)
	{
		new_node(&data.stack_a, ft_atoi(argv[i]));
		i++;
	}
	num_index_100(&data.stack_a, argc);
	if (!check_sorted_a(&data.stack_a))
		exit(0);
	if (argc < 7)
		small_stack(&data.stack_a, &data.stack_b, argc);
	else
		big_stack(&data.stack_a, &data.stack_b, argc);
	exit(0);
}
