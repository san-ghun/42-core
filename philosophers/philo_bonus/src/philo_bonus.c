/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:07:57 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/19 16:45:16 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	check_status(t_resource *rsc)
{
	int		i;
	sem_t	*printlock;

	i = -1;
	printlock = rsc->printlock;
	sem_wait(printlock);
	while (++i < rsc->n_philos)
	{
		if (rsc->time_die + rsc->philos[i]->t_last_meal < get_time_ms())
		{
			print_dead(rsc->philos[i], rsc);
			sem_post(printlock);
			return (1);
		}
	}
	sem_post(printlock);
	return (0);
}

void	*died_philosopher(t_philo *philo, t_resource *rsc)
{
	sem_wait(rsc->forks);
	print_status(philo, single_rsc(), "has taken a fork");
	usleep(single_rsc()->time_die * 1001);
	sem_post(rsc->forks);
	exit(EXIT_SUCCESS);
}

void	*philosopher(t_philo *philo)
{
	t_resource	*rsc;

	rsc = single_rsc();
	if (rsc->n_philos == 1)
		died_philosopher(philo, rsc);
	// if (philo->id % 2 == 1)
	// 	usleep(rsc->time_eat * 100);
	// else if ((philo->id == rsc->n_philos - 1) && (rsc->n_philos % 2 == 1))
	// 	usleep(rsc->time_eat * 900);
	while (rsc->funeral != 1)
	{
		if (philo->id != *(rsc->next))
		{
			usleep(10);
			continue ;
		}
		eat(philo, rsc);
		if (philo->n_ate == rsc->n_eat_opt)
			break ;
		jam(philo, rsc);
		think(philo, rsc);
	}
	exit(EXIT_SUCCESS);
}

void	init_table(t_resource *rsc)
{
	int		i;
	pid_t	pid;

	i = -1;
	while (++i < rsc->n_philos)
	{
		rsc->philos[i]->t_launch = get_time_ms();
		rsc->philos[i]->t_last_meal = rsc->philos[i]->t_launch;
		// pthread_create(rsc->philosophers[i], NULL, (void *)philosopher, rsc->philos[i]);
		rsc->philos[i]->pid = fork();
		if (rsc->philos[i]->pid == 0)
			philosopher(rsc->philos[i]);
	}
	return ;
}

int	main(int argc, char *argv[])
{
	int				i;
	t_resource		*rsc;

	if (check_args(argc, argv) != 0)
		return (1);
	rsc = init_resource(ft_atoi(argv[1]), ft_atoi(argv[2]), \
						ft_atoi(argv[3]), ft_atoi(argv[4]));
	if (argc == 6)
		rsc->n_eat_opt = ft_atoi(argv[5]);
	init_table(rsc);
	while (rsc->funeral != 1 && rsc->n_eat_opt < 0)
	{
		check_status(rsc);
		usleep(100);
	}
	i = -1;
	while (++i < rsc->n_philos)
		kill(rsc->philos[i]->pid, SIGKILL);
	free_resource();
	return (0);
}
