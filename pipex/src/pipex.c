/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 13:29:41 by imisumi           #+#    #+#             */
/*   Updated: 2023/02/28 16:56:25 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_msg(char *msg, char *msg2, int x)
{
	write(STDERR, msg, ft_strlen(msg));
	if (msg2)
		write(STDERR, msg2, ft_strlen(msg2));
	write(STDERR, "\n", 1);
	exit(x);
}

void	exit_error(char *msg, int code)
{
	perror(msg);
	exit(code);
}

void	child_process(char **argv, char **envp, t_pip pip, int child)
{
	if (child == 1)
	{
		close(pip.end[0]);
		dup2(pip.end[1], STDOUT);
		check_cmd(pip.paths, argv, envp, 2);
	}
	else if (child == 2)
	{
		pip.out = open(argv[4], O_TRUNC | O_WRONLY | O_CREAT, 0644);
		if (pip.out == -1)
			exit_error(argv[4], 1);
		dup2(pip.end[0], STDIN);
		close(pip.end[1]);
		dup2(pip.out, STDOUT);
		close(pip.out);
		check_cmd(pip.paths, argv, envp, 3);
	}
}

void	child_two(char **argv, char **envp, t_pip pip)
{
	pip.out = open(argv[4], O_TRUNC | O_WRONLY | O_CREAT, 0777);
	if (pip.out == -1)
		exit_error(argv[4], 1);
	dup2(pip.end[0], STDIN);
	close(pip.end[1]);
	dup2(pip.out, STDOUT);
	close(pip.out);
	check_cmd(pip.paths, argv, envp, 3);
}

// void	pipex(char *argv[], char *envp[], t_pip pip)
// {
// 	pip.in = open(argv[1], O_RDONLY);
// 	if (pip.in == -1)
// 		exit_error(argv[1], 1);
// 	dup2(pip.in, STDIN);
// 	close(pip.in);
// 	pip.paths = env_paths(envp);
// 	if (pipe(pip.end) == -1)
// 		exit_error("Pipe", 1);
// 	pip.pid_1 = fork();
// 	if (pip.pid_1 == -1)
// 		exit_error("Fork", 1);
// 	else if (pip.pid_1 == 0)
// 		child_process(argv, envp, pip, 1);
// 	pip.pid_2 = fork();
// 	if (pip.pid_2 == -1)
// 		exit_error("Fork", 1);
// 	else if (pip.pid_2 == 0)
// 		child_process(argv, envp, pip, 2);
// 	close(pip.end[0]);
// 	close(pip.end[1]);
// 	waitpid(pip.pid_1, NULL, 0);
// 	waitpid(pip.pid_2, NULL, 0);
// }

void	parent_process(t_pip pip)
{
	int	status;
	int	code;

	status = 0;
	close(pip.end[0]);
	close(pip.end[1]);
	waitpid(pip.pid_1, NULL, 0);
	waitpid(pip.pid_2, &status, 0);
	if (status)
	{
		code = WEXITSTATUS(status);
		exit(code);
	}
}

void	pipex(char *argv[], char *envp[], t_pip pip)
{
	pip.in = open(argv[1], O_RDONLY);
	if (pip.in == -1)
		exit_error(argv[1], 1);
	dup2(pip.in, STDIN);
	close(pip.in);
	pip.paths = env_paths(envp);
	if (pipe(pip.end) == -1)
		exit_error("Failed to create pipe", 1);
	pip.pid_1 = fork();
	if (pip.pid_1 == -1)
		exit_error("Failed to create fork", 1);
	else if (pip.pid_1 == 0)
		child_process(argv, envp, pip, 1);
	pip.pid_2 = fork();
	if (pip.pid_2 == -1)
		exit_error("Failed to create fork", 1);
	else if (pip.pid_2 == 0)
	{
		waitpid(pip.pid_2, NULL, 0);
		child_process(argv, envp, pip, 2);
	}
	parent_process(pip);
}

int	main(int argc, char *argv[], char *envp[])
{
	t_pip	pip;

	if (argc == 5)
		pipex(argv, envp, pip);
	else
	{
		write(STDERR, "Invalid number of arguments\n", 28);
		return (1);
	}
}
