/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:54:34 by imisumi           #+#    #+#             */
/*   Updated: 2023/02/21 17:03:15 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	exit_msg(char *msg)
{
	printf("%s", msg);
	exit(0);
}

// int	main(void)
// {
// 	int	in;

// 	in = open("infile", O_RDONLY);
// 	dup2(in, STDIN_FILENO);
// 	close(in);
// 	char	*argv[] = {"/bin/ls", "-l", NULL};
// 	int val = execve(argv[0], argv, NULL);
// 	if (val == -1)
// 		perror("Error\n");
// 	printf("Done with execve\n");
// }

void	child_process(int file1, char *cmd1)
{
	printf("Child\n");
}

void	parent_process(int file2, char *cmd2)
{
	wait(NULL);

// int	main(void)
// {
// 	int	file[2];
// 	if (access("infile", F_OK) == -1)
// 		exit_msg("No infile\n");
// 	file[0] = c
// 	if (file[0] == -1)
// 		return (2);
// 	file[1] = dup2(file[0], STDOUT_FILENO);
// 	close(file[0]);
// 	printf("111");
// }

// int	main(void)
// {
// 	int	out;
// 	int	in;

// 	if (access("infile", F_OK) == -1)
// 		exit_msg("No infile\n");
// 	out = open("outfile", O_WRONLY | O_CREAT, 0777);
// 	if (out == -1)
// 		return (2);
// 	dup2(out, STDOUT_FILENO);
// 	close(out);
// 	printf("111");
// }

// int	main(void)
// {
// 	int		file[2];
// 	pid_t	parent;

// 	if (access("infile", F_OK) == -1)
// 		exit_msg("No infile\n");
// 	file[0] = open("infile", O_RDONLY);
// 	if (file[0] == -1)
// 		return (2);
// 	close(file[0]);
// 	parent = fork();
// 	if (parent < 0)
// 		exit_msg("Fork failed\n");
// 	if (parent == 0)
// 		child_process(1, 1);
// 	else
// 		parent_process(1, 1);
// }

// int	main(void)
// {
// 	int	arr[] = {1, 2, 3, 4, 1, 2, 7, 4};
// 	int	arrSize = sizeof(arr) / sizeof(int);
// 	int	start, end;
// 	int	fd[2];
// 	if (pipe(fd) == -1)
// 		return (1);
// 	int	id = fork();
// 	if (id == -1)
// 		return (1);
// 	if (id == 0)
// 	{
// 		start = 0;
// 		end = start + arrSize / 2;
// 	}
// 	else
// 	{
// 		start = arrSize / 2;
// 		end = arrSize;
// 	}
// 	int	sum = 0;
// 	int	i;
// 	for (i = start; i < end; i++)
// 		sum += arr[i];
// 	printf("calculated partial sum: %d\n", sum);
// 	if (id == 0)
// 	{
// 		close(fd[0]);
// 		write(fd[1], &sum, sizeof(sum));
// 		close(fd[1]);
// 	}
// 	else
// 	{
// 		int	sumFromChild;
// 		close(fd[1]);
// 		read(fd[0], &sumFromChild, sizeof(sumFromChild));
// 		close(fd[0]);

// 		int totalsum = sum + sumFromChild;
// 		printf("total sum = %d\n", totalsum);
// 		wait(NULL);
// 	}
// }




// int	main(void)
// {
// 	int	arr[] = {1, 2, 3, 4, 1, 2, 7, 4};
// 	int	arrSize = sizeof(arr) / sizeof(int);
// 	int	start, end;
// 	int	fd[2]; // fd[0] - read, fd[1] - write
// 	if (pipe(fd) == -1)
// 		return (1);
// 	int	id = fork();
// 	if (id == -1)
// 		return (1);
// 	if (id == 0)
// 	{
// 		start = 0;
// 		end = start + arrSize / 2;
// 	}
// 	else
// 	{
// 		start = arrSize / 2;
// 		end = arrSize;
// 	}
// 	int	sum = 0;
// 	int	i;
// 	for (i = start; i < end; i++)
// 		sum += arr[i];
// 	printf("calculated partial sum: %d\n", sum);
// 	if (id == 0) // child proccess
// 	{
// 		close(fd[0]);
// 		write(fd[1], &sum, sizeof(sum));
// 		close(fd[1]);
// 	}
// 	else		//parent proccess
// 	{
// 		int	sumFromChild;
// 		close(fd[1]);
// 		read(fd[0], &sumFromChild, sizeof(sumFromChild));
// 		close(fd[0]);

// 		int totalsum = sum + sumFromChild;
// 		printf("total sum = %d\n", totalsum);
// 		wait(NULL);
// 	}
// }

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

// void	check_cmd(char **paths, char **argv, char **envp)
// {
// 	char	**mycmdargs;
// 	char	*cmd;
// 	int		i;

// 	// printf("hey\n");
// 	mycmdargs = ft_split(argv[2], ' ');
// 	i = -1;
// 	while (paths[++i])
// 	{
// 		cmd = ft_strjoin(paths[i], argv[2]);
// 		printf("%s\n", cmd);
// 		execve(cmd, mycmdargs, envp);
// 		free(cmd);
// 	}
// }

void	check_cmd(char **paths, char **argv, char **envp)
{
	char	**cmd_arg;
	char	*cmd_path;
	int		i;

	cmd_arg = ft_split(argv[2], ' ');
	i = -1;
	while (paths[++i])
	{
		cmd_path = ft_strjoin(paths[i], cmd_arg[0]);
		
		execve(cmd_path, cmd_arg, 0);
		// printf("%s\n", cmd_path);
		free(cmd_path);
	}
}

int	main(int argc, char *argv[], char *envp[])
{
	int		in;
	int		out;
	char	**paths;

	
	if (access("infile", F_OK) == -1)
		exit_msg("No infile\n");
	in = open("infile", O_RDONLY);
	dup2(in, STDIN_FILENO);
	close (in);
	// char	*temp[] = {"/bin/ls", "-l", NULL};
	// execve(temp[0], temp, envp);
	// exit (0);
	paths = env_paths(envp);
	check_cmd(paths, argv, envp);
	
	// char	*ar[] = {"/bin/ls", "-l", NULL};
	// int val = execve(ar[0], ar, envp);
	// int	i = 0;
	// while (paths[i])
	// {
	// 	printf("%s\n", paths[i]);
	// 	i++;
	// }
	
}