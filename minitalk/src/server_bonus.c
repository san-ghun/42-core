/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:06:33 by sanghupa          #+#    #+#             */
/*   Updated: 2023/02/21 15:32:54 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	ft_server_error(int pid_s, int f(void))
{
	int		err;
	char	*res_msg;

	err = f();
	if (!pid_s)
	{
		res_msg = "Result: Failed to start server.\n";
		ft_printf("%s", res_msg);
		ft_printf("Try: ./server\n");
	}
	else
	{
		res_msg = "Result: server #%d failed to receive message from client\n";
		ft_printf(res_msg, pid_s);
	}
	return (err);
}

static void	ft_message_handler(int signal)
{
	static int	bit;
	static int	i;

	if (signal == SIGUSR1)
	{
		i |= (1 << bit);
	}
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
		return (ft_server_error(0, ft_error_argc));
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	ft_printf("Wating for message from client...\n------------\n");
	while (argc == 1)
	{
		signal(SIGUSR1, ft_message_handler);
		signal(SIGUSR2, ft_message_handler);
	}
	return (0);
}
