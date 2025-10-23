/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   join.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:23:45 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/18 07:24:10 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*join_str(char *s1, char *s2)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	ptr = (char *)malloc(get_len(s1) + get_len(s2) + 1);
	if (ptr)
	{
		while (*s1)
			ptr[i++] = *s1++;
		while (*s2)
			ptr[i++] = *s2++;
		ptr[i] = '\0';
		return (ptr);
	}
	return (ptr);
}

/*
int main()
{
	char *s = join("Hello ", "there");
	printf("%s\n", s);
	free(s);
}
*/