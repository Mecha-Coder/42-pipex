/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:10:29 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/18 07:10:29 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	open_file(char *file, int filemode)
{
	int	fd;

	if (filemode == 0)
		fd = open(file, O_RDONLY, 0777);
	if (filemode == 1)
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (filemode == 2)
		fd = open(file, O_WRONLY | O_CREAT | O_APPEND, 0777);
	if (fd == -1)
		error_handler(file, SHOW, EXIT_FAILURE);
	return (fd);
}
