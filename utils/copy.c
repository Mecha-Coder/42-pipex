/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 13:57:53 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/18 13:57:53 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	copy(char *cmd, char *holder)
{
	int	i;

	i = 0;
	while (cmd && *cmd)
		holder[i++] = *cmd++;
	holder[i] = '\0';
}

void	concat(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i])
		i++;
	while (*s2)
		s1[i++] = *s2++;
	s1[i] = '\0';
}
