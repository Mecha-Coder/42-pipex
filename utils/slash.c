/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:25:05 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/18 07:25:05 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	add_slash(char *cmd, char *holder)
{
	int	i;

	i = 0;
	holder[i++] = '/';
	while (cmd && *cmd)
		holder[i++] = *cmd++;
	holder[i] = 0;
}

/*
int main()
{
	char s[] = "cat";
	char new[30];

	add_slash(s, new);
	printf("[%s]\n", new);
}
*/