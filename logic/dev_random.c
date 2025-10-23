/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dev_random.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 18:53:43 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/18 18:53:43 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	write_to_pipe(char *filename, int *fd)
{
	int		infd;
	char	data[BUFFER];

	close(fd[0]);
	infd = open_file(filename, INFILE);
	if (read(infd, data, BUFFER) != BUFFER)
		error_handler("dev_random reading", PERROR, EXIT_FAILURE);
	close(infd);
	if (write(fd[1], data, BUFFER) != BUFFER)
		error_handler("dev_random write issue", PERROR, EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}

void	dev_random(char *filename)
{
	int		fd[2];
	pid_t	id;

	if (pipe(fd) < 0)
		error_handler("dev_random pipe", PERROR, EXIT_FAILURE);
	if (fcntl(fd[1], F_SETPIPE_SZ, 512 * 1024) < 0)
		error_handler("fcntl", PERROR, EXIT_FAILURE);
	id = fork();
	if (id < 0)
		error_handler("dev_random fork", PERROR, EXIT_FAILURE);
	if (!id)
		write_to_pipe(filename, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}
