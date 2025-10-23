/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:07:44 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/18 07:07:44 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	execute(char *cmd, char **env)
{
	char	**arg;
	char	*path;
	char	error[50];

	reset(error, sizeof(error));
	if (!cmd[0])
		return ;
	arg = split(cmd, ' ');
	path = get_path(arg[0], env);
	if (!path)
	{
		copy(arg[0], error);
		concat(error, ": command not found\n");
		freelist(arg);
		error_handler(error, PRINT, 127);
	}
	if (execve(path, arg, env) < 0)
	{
		freelist(arg);
		free(path);
		error_handler("execute", PERROR, EXIT_FAILURE);
	}
}
