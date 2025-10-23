/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpaul <jpaul@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 07:42:30 by jpaul             #+#    #+#             */
/*   Updated: 2024/09/18 07:42:30 by jpaul            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

//********************************************
// LIBRARIES
//********************************************

# include "./get_next_line/get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stddef.h>
# include <sys/wait.h>
# include <stdio.h>

//********************************************
// CONSTANTS
//********************************************

# define BUFFER 4096

# ifndef F_SETPIPE_SZ
#  define F_SETPIPE_SZ 1031
# endif

// Toggle is used to enable splitting of this type of words "'p  '" 
# define TOGGLE 0

// Error type
# define PRINT 0
# define PERROR 1
# define SHOW 2

//File mode
# define INFILE 0
# define OUTFILE_TRUNC 1
# define OUTFILE_APPEND 2

// Error Message
# define ARG_4_ERR "Input: Only can have 4 argument\n"
# define ARG_4_ERR_B "Input: Argument is less than 4\n"
# define ARG_HERE_DOC_ERR "Input: here_doc command need at least 5 arguments\n"
# define ARG_SAME_FILE "Input: infile & outfile can't the same\n"
# define INVALID_CMD "cmd: Invalid command\n"

//********************************************
// PROTOTYPES
//********************************************

// [LOGIC]

void	do_pipe(char *cmd, char **env);
void	error_handler(char *s, int type, int exit_code);
void	execute(char *cmd, char **env);
char	*get_path(char *cmd, char **env);
void	here_doc(char *limiter);
int		open_file(char *file, int filemode);
void	dev_random(char *filname);

// [UTILS]

void	freelist(char **list);
char	*join_str(char *s1, char *s2);
int		get_len(char *s);
void	print_fd(char *s, int fd);
char	**split(char *s, char c);
int		cmp_str(char *s1, char *s2, int n);
void	add_slash(char *cmd, char *holder);
void	copy(char *cmd, char *holder);
void	concat(char *s1, char *s2);
void	reset(void *dst, size_t len);
#endif
