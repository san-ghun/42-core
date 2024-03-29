/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 22:08:42 by sanghupa          #+#    #+#             */
/*   Updated: 2023/02/25 21:15:33 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

static int	ft_client_error(int pid_c, int pid_s, int f(void))
{
	int		err;
	char	*res_msg;

	err = f();
	if (!pid_s)
	{
		res_msg = "Result: client #%d failed to send message\n";
		ft_printf(res_msg, pid_c);
	}
	else
	{
		res_msg = "Result: client #%d failed to send message to server #%d\n";
		ft_printf(res_msg, pid_c, pid_s);
	}
	ft_printf("Try: ./client <PID> \"<message>\"\n");
	return (err);
}

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

static void	ft_response_handler(int signal)
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
	int	i;
	int	pid_c;
	int	pid_s;

	i = 0;
	pid_c = getpid();
	if (argc != 3)
		return (ft_client_error(pid_c, 0, ft_error_argc));
	else if (!ft_str_isdigit(argv[1]))
		return (ft_client_error(pid_c, 0, ft_error_argv));
	else
	{
		pid_s = atoi(argv[1]);
		while (argv[2][i] != '\0')
		{
			ft_send_message(pid_s, argv[2][i]);
			ft_printf("%x\n", argv[2][i]);
			i++;
		}
		ft_send_message(pid_s, '\n');
	}
	return (0);
}
