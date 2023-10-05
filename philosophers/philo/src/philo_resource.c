/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_resource.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:48 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/05 17:47:36 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_resource	*resource_singleton(void)
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
	};
	is_init = 1;
	return (&this);
}

void	free_resource(void)
{
	t_resource	*rsc;
	int			i;
	size_t		n_philo;

	rsc = resource_singleton();
	i = 0;
	n_philo = rsc->n_philos;
	while (i < n_philo)
	{
		free(rsc->philosophers[i]);
		free(rsc->forks[i]);
		free(rsc->philos[i]);
		i++;
	}
	free(rsc->philos);
	free(rsc->philosophers);
	free(rsc->forks);
	free(rsc->printlock);
	// return ;
}
