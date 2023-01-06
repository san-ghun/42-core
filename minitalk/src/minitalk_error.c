/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 00:55:32 by sanghupa          #+#    #+#             */
/*   Updated: 2023/01/06 01:30:38 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_str_isdigit(char *str)
{
	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}
	return (1);
}

int	ft_client_error(int pid_c, int pid_s, int f(void))
{
	int		err;
	char	*res_msg;

	err = f();
	if (!pid_s)
	{
		res_msg = "Result: client #%d failed to send message\n";
		printf(res_msg, pid_c);
	}
	else
	{
		res_msg = "Result: client #%d failed to send message to server #%d\n";
		printf(res_msg, pid_c, pid_s);
	}
	printf("Try: ./client <PID> \"<message>\"\n");
	return (err);
}

int	ft_server_error(int pid_s, int f(void))
{
	int		err;
	char	*res_msg;

	err = f();
	if (!pid_s)
	{
		res_msg = "Result: Failed to start server.\n";
		printf("%s", res_msg);
		printf("Try: ./server\n");
	}
	else
	{
		res_msg = "Result: server #%d failed to receive message to client\n";
		printf(res_msg, pid_s);
	}
	return (err);
}

int	ft_error_argv(void)
{
	printf("Error: Invalid argument - PID\n");
	return (1);
}

int	ft_error_argc(void)
{
	printf("Error: Invalid argument - argument list\n");
	return (1);
}
