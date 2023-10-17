/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:12:35 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/11 23:31:52 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_args(int argc, char *argv[])
{
	if (argc > 4 && argc <= 6)
	{
		if (ft_atoi(argv[1]) < 1)
			return (printf("Number_of_philosophers must be at least 1.\n"));
		if (ft_atoi(argv[2]) < 1)
			return (printf("Time_to_die must be at least 1.\n"));
		if (ft_atoi(argv[3]) < 1)
			return (printf("Time_to_eat must be at least 1.\n"));
		if (ft_atoi(argv[4]) < 1)
			return (printf("Time_to_sleep must be at least 1.\n"));
		if (argc == 6 && ft_atoi(argv[5]) < 1)
			return (printf("Number_of_times_each_philosopher_must_eat \
must be at least 1.\n"));
	}
	else
	{
		printf("TRY > ./philo [number_of_philosophers] ");
		printf("[time_to_die] [time_to_eat] [time_to_sleep]\n");
		printf("(Optional) [number_of_times_each_philosophers_must_eat]\n");
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
	}
	return (sign * result);
}

long long	get_time_ms(void)
{
	static struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec) * 1000 + (tv.tv_usec) / 1000);
}

void	print_status(t_philo *philo, t_resource *rsc, char *str, int nlock)
{
	pthread_mutex_lock(rsc->printlock[nlock]);
	if (rsc->funeral != 1)
	{
		printf("%lld %u %s\n", get_time_ms() - philo->t_launch, \
				philo->id + 1, str);
	}
	pthread_mutex_unlock(rsc->printlock[nlock]);
}

void	print_dead(t_philo *philo, t_resource *rsc)
{
	if (rsc->funeral != 1)
	{
		rsc->funeral = 1;
		philo->status = 0;
		printf("%lld %u %s\n", get_time_ms() - philo->t_launch, \
				philo->id + 1, "died");
		usleep(1000);
	}
}
