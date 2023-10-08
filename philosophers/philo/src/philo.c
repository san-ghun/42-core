/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:07:53 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/07 23:22:03 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_status(t_philo *philo, t_resource *rsc)
{
	if (get_time_ms() > rsc->time_die + philo->t_last_meal)
		print_dead(philo, rsc);
	return (0);
}

void	*died_philosopher(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_status(philo, single_rsc(), "has taken a fork");
	usleep(single_rsc()->time_die * 1001);
	check_status(philo, single_rsc());
	pthread_mutex_unlock(philo->left);
	return (NULL);
}

// TODO: implement
void	*philosopher(t_philo *philo)
{
	t_resource	*rsc;

	rsc = single_rsc();
	philo->t_launch = get_time_ms();
	philo->t_last_meal = philo->t_launch;
	if (rsc->n_philos == 1)
		return (died_philosopher(philo));
	if (philo->id % 2 == 1)
		usleep(rsc->time_eat * 100);
	else if ((philo->id == rsc->n_philos - 1) || (rsc->n_philos % 2 == 1))
		usleep(rsc->time_eat * 100);
	while (rsc->funeral != 1)
	{
		eat(philo, rsc);
		if (rsc->n_eat_opt && (philo->n_ate == rsc->n_eat_opt))
			break ;
		check_status(philo, rsc);
		jam(philo, rsc);
		check_status(philo, rsc);
		think(philo, rsc);
		check_status(philo, rsc);
	}
	return (0);
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
	i = -1;
	while (++i < rsc->n_philos)
	{
		pthread_create(rsc->philosophers[i], NULL, \
			(void *)philosopher, rsc->philos[i]);
	}
	i = -1;
	while (++i < rsc->n_philos)
		pthread_join(*(rsc->philosophers[i]), NULL);
	free_resource();
	return (0);
}
