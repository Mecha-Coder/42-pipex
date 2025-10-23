/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:39:44 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/18 07:39:44 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(int *fd, char **av, char **env)
{
	int	infd;
	int	blank;

	close(fd[0]);
	infd = open_file(av[1], INFILE);
	dup2(fd[1], STDOUT_FILENO);
	if (infd == -1)
	{
		blank = open("/dev/null", O_RDONLY);
		dup2(blank, STDIN_FILENO);
	}
	else
		dup2(infd, STDIN_FILENO);
	execute(av[2], env);
}

void	parent(int *fd, char **av, char **env)
{
	int	outfd;
	int	destroy;

	close(fd[1]);
	outfd = open_file(av[4], OUTFILE_TRUNC);
	dup2(fd[0], STDIN_FILENO);
	if (outfd == -1)
	{
		destroy = open("/dev/null", O_WRONLY);
		dup2(destroy, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	else
		dup2(outfd, STDOUT_FILENO);
	execute(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int	fd[2];
	int	id;

	if (ac != 5)
		error_handler(ARG_4_ERR, PRINT, EXIT_FAILURE);
	if (pipe(fd) < 0)
		error_handler("pipe", PERROR, EXIT_FAILURE);
	if (fcntl(fd[1], F_SETPIPE_SZ, 512 * 1024) < 0)
		error_handler("fcntl", PERROR, EXIT_FAILURE);
	id = fork();
	if (id < 0)
		error_handler("fork", PERROR, EXIT_FAILURE);
	if (!id)
		child(fd, av, env);
	wait(NULL);
	parent(fd, av, env);
}
