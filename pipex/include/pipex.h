/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 12:27:45 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/15 13:04:59 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

// open 
# include <fcntl.h>

// close read write access dup dup2 execve exit fork pipe unlink 
# include <unistd.h>

// malloc free 
# include <stdlib.h>

// perror
# include <stdio.h>

// strerror
# include <string.h>

// wait waitpid
# include <sys/wait.h>

# include "libft.h"
# include "ft_printf.h"

# include <ctype.h>

// Limit Loop: use addition to while condition
# define MAX_ITER	5000

// Prevent Heap mem leak: use addition to char or array
# define DATA_SIZE	3072

/* pipex.c */

/* pipex_util.c */
void	ft_error(void);
void	ft_exec(char *arg, char *envp[]);
void	instruction(void);
int		get_line(char *line[]);

#endif
