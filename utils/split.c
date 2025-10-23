/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 11:02:59 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/18 11:29:03 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static int	size(char *s, char c)
{
	int	quote;
	int	count;

	quote = 0;
	count = 0;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s && (quote || *s != c))
			{
				if (*s == '\'')
					quote = !quote;
				s++;
			}
		}
		else
			s++;
	}
	return (count + 1);
}

static char	*trim_word(char *s, int size)
{
	char	*word;
	int		i;
	int		offset;

	i = 0;
	offset = 0;
	if (s[0] == '\'' && s[size - 1] == '\'')
	{
		s++;
		offset = 2;
		word = (char *)malloc(size - 1);
	}
	else
		word = (char *)malloc(size + 1);
	if (!word)
		return ("");
	while (i < size - offset)
		word[i++] = *s++;
	word[i] = '\0';
	return (word);
}

static char	**split_it(char *s, char **list, char c)
{
	int	quote;
	int	i;
	int	j;

	j = 0;
	quote = 0;
	while (*s)
	{
		if (*s != c)
		{
			i = 0;
			while (*(s + i) && (quote || *(s + i) != c))
			{
				if (*(s + i) == '\'')
					quote = !quote;
				i++;
			}
			list[j++] = trim_word(s, i);
			s = s + i;
		}
		else
			s++;
	}
	list[j] = NULL;
	return (list);
}

char	**split(char *s, char c)
{
	char	**list;

	list = (char **)malloc(size(s, c) * sizeof(char *));
	if (!list)
		return (NULL);
	return (split_it(s, list, c));
}

/*
static void	freelist(char **list)
{
	int	i;

	i = -1;
	while (list && list[++i])
		free(list[i]);
	if (list)
		free(list);
}

static void answer(char **result)
{
	int i = -1;
	while(result[++i])
		printf("[%s]\n", result[i]);
	printf("------------------------\n\n");
	freelist(result);
}

int main()
{
	char s1[] = "Hello there , Jason here";
	char s2[] = "Hello there , Jason here  ";
	char s3[] = "Random Word Generator is the perfect tool to help you do this. "
			"While this tool isnt a word creator, it is a word generator that "
			"will generate random words for";
	char s4[] = "This is awesome    '{testing space}' try   ' P'";
	char s5[] = "tr x ' '";
	char s6[] = "echo 'Hi 42'";
	char s7[] = "tr ex ' X'";
	char s8[] = "tr pi 'P '";
	char s9[] = "Hello0there,0Jason0here00";

	answer(split(s1, ' '));
	answer(split(s2, ' '));
	answer(split(s3, ' '));
	answer(split(s4, ' '));
	answer(split(s5, ' '));
	answer(split(s6, ' '));
	answer(split(s7, ' '));
	answer(split(s8, ' '));
	answer(split(s9, '0'));
}
*/