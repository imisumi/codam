/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 11:54:34 by imisumi           #+#    #+#             */
/*   Updated: 2023/02/16 15:42:13 by imisumi          ###   ########.fr       */
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
	printf("Parent\n");
}

// int	main(void)
// {
// 	int	file[2];

// 	if (access("infile", F_OK) == -1)
// 		exit_msg("No infile\n");
// 	file[0] = open("outfile", O_WRONLY | O_CREAT, 0777);
// 	if (file[0] == -1)
// 		return (2);
// 	file[1] = dup2(file[0], STDOUT_FILENO);
// 	close(file[0]);
// 	printf("hey");
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

int	main(void)
{
	int	arr[] = {1, 2, 3, 4, 1, 2, 7, 4};
	int	arrSize = sizeof(arr) / sizeof(int);
	int	start, end;
	int	fd[2];
	if (pipe(fd) == -1)
		return (1);
	int	id = fork();
	if (id == -1)
		return (1);
	if (id == 0)
	{
		start = 0;
		end = start + arrSize / 2;
	}
	else
	{
		start = arrSize / 2;
		end = arrSize;
	}
	
	int	sum = 0;
	int	i;
	for (i = start; i < end; i++)
		sum += arr[i];
	printf("calculated partial sum: %d\n", sum);
	
	if (id == 0)
	{
		close(fd[0]);
		write(fd[1], &sum, sizeof(sum));
		close(fd[1]);
	}
	else
	{
		int	sumFromChild;
		close(fd[1]);
		read(fd[0], &sumFromChild, sizeof(sumFromChild));
		close(fd[0]);

		int totalsum = sum + sumFromChild;
		printf("total sum = %d\n", totalsum);
		wait(NULL);
	}
}
