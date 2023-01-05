/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:06:33 by sanghupa          #+#    #+#             */
/*   Updated: 2023/01/05 01:47:55 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
		printf("%c", i);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	(void)argv;
	if (argc != 1)
	{
		printf("Wrong start.\n");
		printf("Try: ./server\n");
		return (1);
	}
	pid = getpid();
	printf("PID: %d\n", pid);
	while (argc == 1)
	{
		signal(SIGUSR1, ft_message_handler);
		signal(SIGUSR2, ft_message_handler);
	}
	return (0);
}
