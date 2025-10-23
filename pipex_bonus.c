/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:39:20 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/18 07:39:20 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	handle_normal(int *outfd, char **av, int ac)
{
	int	blank;
	int	infd;

	infd = open_file(av[1], INFILE);
	*outfd = open_file(av[ac -1], OUTFILE_TRUNC);
	if (infd == -1)
	{
		blank = open("/dev/null", O_RDONLY);
		dup2(blank, STDIN_FILENO);
	}
	else
		dup2(infd, STDIN_FILENO);
	return (2);
}

static int	handle_dev_random(int *outfd, char **av, int ac)
{
	dev_random(av[1]);
	*outfd = open_file(av[ac -1], OUTFILE_TRUNC);
	return (2);
}

static int	handle_here_doc(int *outfd, char **av, int ac)
{
	if (ac < 6)
		error_handler(ARG_HERE_DOC_ERR, PRINT, EXIT_FAILURE);
	here_doc(av[2]);
	*outfd = open_file(av[ac - 1], OUTFILE_APPEND);
	return (3);
}

int	main(int ac, char **av, char **env)
{
	int	outfd;
	int	destroy;
	int	i;

	if (ac < 5)
		error_handler(ARG_4_ERR_B, PRINT, EXIT_FAILURE);
	if (!cmp_str("here_doc", av[1], get_len(av[1])))
		i = handle_here_doc(&outfd, av, ac);
	else if (!cmp_str("/dev/random", av[1], get_len(av[1]))
		|| !cmp_str("/dev/urandom", av[1], get_len(av[1])))
		i = handle_dev_random(&outfd, av, ac);
	else
		i = handle_normal(&outfd, av, ac);
	while (i < ac - 2)
		do_pipe(av[i++], env);
	if (outfd == -1)
	{
		destroy = open("/dev/null", O_WRONLY);
		dup2(destroy, STDOUT_FILENO);
		exit(EXIT_FAILURE);
	}
	else
		dup2(outfd, STDOUT_FILENO);
	execute(av[ac - 2], env);
}
