/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imisumi <imisumi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 21:15:55 by ichiro            #+#    #+#             */
/*   Updated: 2023/02/24 15:49:10 by imisumi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# define PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stddef.h>
# include <errno.h>
# include <sys/types.h>
# include <sys/wait.h>

# include "../lib/libft/includes/libft.h"

void	exit_msg(char *msg, char *msg2, int x);
char	**env_paths(char **envp);
void	check_cmd(char **paths, char **argv, char **envp, int cmd);
void	child_process(char **argv, char **paths, char **envp, int *end);
void	parent_process(char **argv, char **paths, char **envp, int *end);
void	exit_error(char *msg, int code);

#endif