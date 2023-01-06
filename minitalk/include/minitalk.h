/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 21:55:46 by sanghupa          #+#    #+#             */
/*   Updated: 2023/01/06 01:26:15 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
// # include "libft.h"

# include <stdio.h>
# include <ctype.h>

/* server.c */

/* client.c */

/* client_error.c */

int	ft_str_isdigit(char *str);

int	ft_server_error(int pid_s, int f(void));

int	ft_client_error(int pid_c, int pid_s, int f(void));

int	ft_error_argv(void);

int	ft_error_argc(void);

#endif
