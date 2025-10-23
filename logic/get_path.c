/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:08:18 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/18 07:08:18 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**allpath;
	char	*path;
	char	filename[30];

	i = -1;
	reset(filename, sizeof(filename));
	add_slash(cmd, filename);
	while (env[++i])
	{
		if (!cmp_str(env[i], "PATH=", 5))
			break ;
	}
	allpath = split(env[i] + 5, ':');
	i = -1;
	while (allpath[++i])
	{
		path = join_str(allpath[i], filename);
		if (!access(path, F_OK | X_OK))
			break ;
		free(path);
		path = NULL;
	}
	freelist(allpath);
	return (path);
}

/*
void test(char *cmd, char **env)
{
	char *s;

	s = get_path(cmd, env);
	if (!s)
		printf("String is NULL\n");
	else
	{
		printf("%s\n", s);
		free(s);
	}
}

int main(int ac, char **av, char **env)
{
	(void)ac;
	(void)av;

	test("ls", env);
	test("wc", env);
	test("grep", env);
	test("cat", env);
	test("hello", env);
}
*/