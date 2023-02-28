/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:38:38 by imisumi           #+#    #+#             */
/*   Updated: 2023/02/28 15:46:48 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

char	**env_paths(char **envp)
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
			break ;
			// execve(cmd_path, cmd_arg, 0);
		}
		else
			i++;
		free(cmd_path);
	}
	execve(cmd_path, cmd_arg, 0);
	// perror("WRONG");
	exit (127);
	// exit(127);
	// exit_error("Command not found", 127);
	// exit (127);
	// exit_msg("Command not found: ", argv[cmd], 127);
}

// void	child_process(char **argv, char **paths, char **envp, int *end)
// {
// 	close(end[0]);
// 	dup2(end[1], STDOUT_FILENO);
// 	check_cmd(paths, argv, envp, 2);
// }

// void	parent_process(char **argv, char **paths, char **envp, int *end)
// {
// 	int	out;

// 	out = open(argv[4], O_TRUNC | O_WRONLY | O_CREAT, 0644);
// 	if (out == -1)
// 		exit_error(argv[4], 1);
// 	dup2(end[0], STDIN_FILENO);
// 	close(end[1]);
// 	dup2(out, STDOUT_FILENO);
// 	close(out);
// 	check_cmd(paths, argv, envp, 3);
// 	// wait(NULL);
// }
