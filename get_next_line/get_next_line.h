/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:41:57 by jpaul             #+#    #+#             */
/*   Updated: 2024/07/30 11:41:57 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stddef.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# define TRUE 1
# define FALSE 0

# ifdef __APPLE__
#  define LENGTH OPEN_MAX
# elif _WIN32 || _WIN64 || __linux__
#  define LENGTH FOPEN_MAX
# else
#  error "Unsupported operating system"
# endif

// **************** STATEMENT FUNCTION *******************

typedef struct s_data
{
	char	buff[BUFFER_SIZE + 1];
	int		readno;
	int		n;
	char	*temp;
	char	*line;
	int		loop;
	int		skip;
}	t_data;

// **************** HELPER FUNCTION *******************

int		len(char *str);
int		found_new_line(char *str);

char	*join(char *s1, char*s2);
char	*extract(char *str, int n);
char	*trim(char *str, int n);

void	transform(char *buff, int readno);

// ***************** MAIN FUNCTION ********************

char	*get_next_line(int fd);

#endif