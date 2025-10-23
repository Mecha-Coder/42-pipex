/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:49:04 by jpaul             #+#    #+#             */
/*   Updated: 2024/07/30 15:07:19 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*extract(char *str, int n)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str || n < 1)
		return (NULL);
	ptr = (char *)malloc(n + 1);
	if (ptr)
	{
		while (n--)
			ptr[i++] = *str++;
		ptr[i] = '\0';
	}
	return (ptr);
}

int	found_new_line(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\n')
		return (i + 1);
	return (0);
}

char	*join(char *s1, char*s2)
{
	int		i;
	char	*str;

	i = 0;
	str = (char *)malloc(len(s1) + len(s2) + 1);
	if (str)
	{
		while (s1 && *s1)
			str[i++] = *s1++;
		while (s2 && *s2)
			str[i++] = *s2++;
		str[i] = '\0';
	}
	return (str);
}

char	*trim(char *str, int n)
{
	int		i;
	char	*ptr;

	i = 0;
	if (!str || n < 1 || !str[n])
		return (NULL);
	while (str[n + i])
		i++;
	ptr = (char *)malloc(i + 1);
	if (ptr)
	{
		i = 0;
		while (str[n + i])
		{
			ptr[i] = str[n + i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}

void	transform(char *buff, int readno)
{
	char	temp[BUFFER_SIZE + 2];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (buff && readno--)
	{
		if (buff[i])
			temp[j++] = buff[i];
		i++;
	}
	temp[j] = '\0';
	i = 0;
	while (temp[i])
	{
		buff[i] = temp[i];
		i++;
	}
	buff[i] = '\0';
}
