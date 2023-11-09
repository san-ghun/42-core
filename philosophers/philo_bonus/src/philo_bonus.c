/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:07:57 by sanghupa          #+#    #+#             */
/*   Updated: 2023/11/09 14:42:23 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_meal(t_resource *rsc)
{
	int	cnt;

	cnt = -1;
	while (++cnt < rsc->n_philos)
	{
		sem_wait(rsc->eatlock);
		if (rsc->funeral == 1)
			break ;
	}
	sem_post(rsc->deadlock);
	return (NULL);
}

void	*died_philosopher(t_philo *philo, t_resource *rsc)
{
	sem_wait(rsc->forks);
	print_status(philo, rsc, "has taken a fork");
	usleep(rsc->time_die * 1001);
	sem_post(rsc->forks);
	check_status(philo);
	exit(EXIT_SUCCESS);
}

void	*philosopher(t_philo *philo)
{
	t_resource	*rsc;
	pthread_t	th;

	rsc = single_rsc();
	if (rsc->n_philos == 1)
		died_philosopher(philo, rsc);
	pthread_create(&th, NULL, (void *)check_status, philo);
	pthread_detach(th);
	if (philo->id % 2 == 1)
		usleep(rsc->time_eat * 100);
	else if ((philo->id == rsc->n_philos - 1) && (rsc->n_philos % 2 == 1))
		usleep(rsc->time_eat * 900);
	routine(philo, rsc);
	sem_post(rsc->eatlock);
	exit(EXIT_SUCCESS);
}

void	init_table(t_resource *rsc)
{
	int			i;
	long long	time;

	i = -1;
	time = get_time_ms();
	while (++i < rsc->n_philos)
	{
		rsc->philos[i]->t_launch = time;
		rsc->philos[i]->t_last_meal = rsc->philos[i]->t_launch;
		rsc->philos[i]->pid = fork();
		if (rsc->philos[i]->pid == 0)
			philosopher(rsc->philos[i]);
	}
	return ;
}

int	main(int argc, char *argv[])
{
	int			i;
	t_resource	*rsc;
	pthread_t	th;	

	if (check_args(argc, argv) != 0)
		return (1);
	rsc = init_resource(ft_atoi(argv[1]), ft_atoi(argv[2]), \
						ft_atoi(argv[3]), ft_atoi(argv[4]));
	if (argc == 6)
	{
		rsc->n_eat_opt = ft_atoi(argv[5]);
		pthread_create(&th, NULL, (void *)check_meal, rsc);
		pthread_detach(th);
	}
	init_table(rsc);
	sem_wait(rsc->deadlock);
	rsc->funeral = 1;
	i = -1;
	while (++i < rsc->n_philos)
		kill(rsc->philos[i]->pid, SIGKILL);
	if (argc == 6)
		pthread_join(th, NULL);
	free_resource();
	return (0);
}
