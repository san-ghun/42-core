/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:07:53 by sanghupa          #+#    #+#             */
/*   Updated: 2023/11/07 14:11:27 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_status(t_resource *rsc)
{
	int				i;

	i = -1;
	pthread_mutex_lock(rsc->printlock);
	while (++i < rsc->n_philos)
	{
		if (rsc->time_die + rsc->philos[i]->t_last_meal < get_time_ms())
		{
			print_dead(rsc->philos[i], rsc);
			pthread_mutex_unlock(rsc->printlock);
			return (1);
		}
	}
	pthread_mutex_unlock(rsc->printlock);
	return (0);
}

void	*died_philosopher(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_status(philo, single_rsc(), "has taken a fork");
	usleep(single_rsc()->time_die * 1001);
	pthread_mutex_unlock(philo->left);
	return (NULL);
}

void	*philosopher(t_philo *philo)
{
	t_resource	*rsc;

	rsc = single_rsc();
	if (rsc->n_philos == 1)
		return (died_philosopher(philo));
	// if (philo->id % 2 == 1)
	// 	usleep(rsc->time_eat * 100);
	// else if ((philo->id == rsc->n_philos - 1) && (rsc->n_philos % 2 == 1))
	// 	usleep(rsc->time_eat * 900);
	routine(philo, rsc);
	return (0);
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
		pthread_create(rsc->philosophers[i], NULL, 
			(void *)philosopher, rsc->philos[i]);
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
	while (rsc->funeral != 1 && rsc->n_eat_cnt != rsc->n_philos)
	{
		check_status(rsc);
		usleep(100);
	}
	i = -1;
	while (++i < rsc->n_philos)
		pthread_join(*(rsc->philosophers[i]), NULL);
	free_resource();
	return (0);
}
