/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:09:31 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/18 07:09:31 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static void	here_doc_prompt(char *limiter, int *fd)
{
	char	*line;
	int		check;

	close(fd[0]);
	while (1)
	{
		print_fd("> ", STDIN_FILENO);
		line = get_next_line(STDIN_FILENO);
		if (!cmp_str(line, limiter, get_len(limiter)))
		{
			check = get_len(limiter);
			if (line[check] == '\n' || line[check] == '\0')
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
		}
		print_fd(line, fd[1]);
		free(line);
	}
}

void	here_doc(char *limiter)
{
	int		fd[2];
	pid_t	id;

	if (pipe(fd) < 0)
		error_handler("here_doc pipe", PERROR, EXIT_FAILURE);
	if (fcntl(fd[1], F_SETPIPE_SZ, 512 * 1024) < 0)
		error_handler("fcntl", PERROR, EXIT_FAILURE);
	id = fork();
	if (id < 0)
		error_handler("here_doc fork", PERROR, EXIT_FAILURE);
	if (!id)
		here_doc_prompt(limiter, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		wait(NULL);
	}
}
