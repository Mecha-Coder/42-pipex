/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 22:06:35 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/17 22:06:35 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	do_pipe(char *cmd, char **env)
{
	int		fd[2];
	pid_t	id;

	if (pipe(fd) < 0)
		error_handler("do_piping pipe", PERROR, EXIT_FAILURE);
	if (fcntl(fd[1], F_SETPIPE_SZ, 512 * 1024) < 0)
		error_handler("fcntl", PERROR, EXIT_FAILURE);
	id = fork();
	if (id < 0)
		error_handler("do_piping fork", PERROR, EXIT_FAILURE);
	if (!id)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		execute(cmd, env);
	}
	else
	{
		wait(NULL);
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
	}
}
