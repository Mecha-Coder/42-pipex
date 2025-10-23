/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:07:15 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/18 07:07:15 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_handler(char *s, int type, int exit_code)
{
	dup2(STDERR_FILENO, STDOUT_FILENO);
	if (type == 2)
	{
		perror(s);
		return ;
	}
	else if (type == 1)
		perror(s);
	else
		print_fd(s, STDERR_FILENO);
	exit(exit_code);
}
