/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ichiro <ichiro@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:54:34 by imisumi           #+#    #+#             */
/*   Updated: 2023/02/23 19:53:37 by ichiro           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_msg(char *msg, char *msg2)
{
	write(STDERR_FILENO, msg, ft_strlen(msg));
	if (msg2)
		write(STDERR_FILENO, msg2, ft_strlen(msg2));
	write(STDERR_FILENO, "\n", 1);
	exit(2);
}

char **env_paths(char **envp)
{
	char	*env;
	char	**paths;
	int		i;

	i = 0;
	while (envp[i])
	{
		env = ft_strnstr(envp[i], "PATH", 4);
		if (env != NULL)
			break ;
		i++;
	}
	env = env + 5;
	paths = ft_split(env, ':');
	i = 0;
	while (paths[i])
	{
		paths[i] = ft_strjoin(paths[i], "/");
		i++;
	}
	return (paths);
}

void	check_cmd(char **paths, char **argv, char **envp, int cmd)
{
	char	**cmd_arg;
	char	*cmd_path;
	int		i;

	cmd_arg = ft_split(argv[cmd], ' ');
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], cmd_arg[0]);
		if (access(cmd_path, F_OK) == 0)
		{
			execve(cmd_path, cmd_arg, 0);
		}
		else
			i++;
		free(cmd_path);
	}
	exit_msg(argv[cmd], ", is not a valid command\n");
}

void	child_process(char **argv, char **paths, char **envp, int *fd)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	check_cmd(paths, argv, envp, 2);
}

void	parent_process(char **argv, char **paths, char **envp, int *fd)
{
	int	out;

	wait(NULL);
	out = open(argv[4], O_TRUNC | O_WRONLY | O_CREAT, 0777);
	if (out == -1)
		exit_msg("failed to open or create ", argv[4]);
	if (dup2(fd[0], STDIN_FILENO) == -1)
		exit_msg("dup2 failed", NULL);
	close(fd[1]);
	if (dup2(out, STDOUT_FILENO) == -1)
		exit_msg("dup2 failed", NULL);
	close(out);
	check_cmd(paths, argv, envp, 3);
}

int	main(int argc, char *argv[], char *envp[])
{
	int		in;
	int		id;
	int		fd[2]; // [0] == read - [1] == write
	char	**paths;

	if (argc != 5)
		exit_msg("expectec 5 arguments - ./pipex file1 \"cmd1\" \"cmd2\" file2", NULL);
	if (access(argv[1], F_OK) == -1)
		exit_msg(argv[1], " does not exist");
	in = open("infile", O_RDONLY);
	if (in == -1)
		exit_msg("failed to open", argv[1]);
	paths = env_paths(envp);
	if (dup2(in, STDIN_FILENO) == -1)
		exit_msg("dup2 failed", NULL);
	close (in);
	if (pipe(fd) == -1)
		exit_msg("pipe failed", NULL);
	id = fork(); // child = 0 / parent = 1
	if (id == -1)
		exit_msg("fork failed", NULL);
	if (id == 0)
		child_process(argv, paths, envp, fd);
	else
		parent_process(argv, paths, envp, fd);
}
