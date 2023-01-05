/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:08:42 by sanghupa          #+#    #+#             */
/*   Updated: 2023/01/05 22:22:32 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_message(pid_t pid, int c)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((1 << bit) & c)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(1000);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	i;
	int	pid_c;
	int	pid_s;

	i = 0;
	pid_c = getpid();
	if (argc == 3)
	{
		pid_s = atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_message(pid_s, argv[2][i]);
			printf("%x\n", argv[2][i]);
			i++;
		}
		ft_send_message(pid_s, '\n');
	}
	else
	{
		printf("Error: client #%d failed to send message to server\n", pid_c);
		printf("Try: ./client <PID> \"<message>\"\n");
		return (1);
	}
	return (0);
}
