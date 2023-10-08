/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_resource.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:48 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/07 16:33:53 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_resource	*single_rsc(void)
{
	static t_resource	this;
	static int			is_init;

	if (is_init)
		return (&this);
	this = (t_resource){
		.n_philos = 0,
		.time_die = 0,
		.time_eat = 0,
		.time_jam = 0,
		.n_eat_opt = 0,
		.philos = NULL,
		.philosophers = NULL,
		.forks = NULL,
		.printlock = NULL,
		.rip = NULL,
		.funeral = 0,
	};
	is_init = 1;
	return (&this);
}

void	free_resource(void)
{
	t_resource	*rsc;
	int			i;
	size_t		n_philo;

	rsc = single_rsc();
	i = 0;
	n_philo = rsc->n_philos;
	while (i < n_philo)
	{
		pthread_mutex_destroy(rsc->forks[i]);
		free(rsc->philosophers[i]);
		free(rsc->forks[i]);
		free(rsc->philos[i]);
		i++;
	}
	pthread_mutex_destroy(rsc->printlock);
	pthread_mutex_destroy(rsc->rip);
	free(rsc->philos);
	free(rsc->philosophers);
	free(rsc->forks);
	free(rsc->printlock);
	free(rsc->rip);
	return ;
}
