/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:07:53 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/06 16:24:00 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_status(void)
{
	int			i;
	t_philo		**philos;
	t_resource	*rsc;

	i = -1;
	rsc = single_rsc();
	philos = rsc->philos;
	while (++i < rsc->n_philos)
		if (get_time_ms() - philos[i]->t_last_meal > rsc->time_die)
			return (die(philos[i]));
	return (0);
}

void	*died_philosopher(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_status(philo, 0);
	usleep(single_rsc()->time_die * 1000);
	check_status();
	pthread_mutex_unlock(philo->left);
	return (NULL);
}

// TODO: implement
void	*philosopher(t_philo *philo)
{
	// size_t	meals;

	// meals = single_rsc()->n_eat_opt;
	if (single_rsc()->n_philos == 1)
		return (died_philosopher(philo));
	while (single_rsc()->funeral != 1)
	{
		// TODO: check meals
		eat(philo);
		jam(philo);
		think(philo);
		check_status();
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
