/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:54:34 by imisumi           #+#    #+#             */
/*   Updated: 2023/02/24 16:18:45 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_msg(char *msg, char *msg2, int x)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	if (msg2)
		write(STDERR_FILENO, msg2, ft_strlen(msg2));
	write(STDERR_FILENO, "\n", 1);
	exit(x);
}

void	exit_error(char *msg, int code)
{
	perror(msg);
	exit(code);
}

// end[0] reads from end[1]
int	main(int argc, char *argv[], char *envp[])
{
	int		in;
	int		id;
	int		end[2];
	char	**paths;

	if (argc != 5)
		exit_msg("Invalid number of arguments", NULL, 1);
	in = open(argv[1], O_RDONLY);
	if (in == -1)
		exit_error(argv[1], 1);
	dup2(in, STDIN_FILENO);
	close (in);
	paths = env_paths(envp);
	if (pipe(end) == -1)
		exit_error("Pipe", 1);
	id = fork();
	if (id == -1)
		exit_error("Fork", 1);
	if (id == 0)
	{
		child_process(argv, paths, envp, end);
	}
	else
	{
		parent_process(argv, paths, envp, end);
	}
}
