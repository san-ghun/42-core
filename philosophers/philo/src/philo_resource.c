/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_resource.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:48 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/11 23:30:42 by sanghupa         ###   ########.fr       */
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
		.n_eat_opt = -1,
		.time_table = NULL,
		.next = NULL,
		.philos = NULL,
		.philosophers = NULL,
		.forks = NULL,
		.printlock = {},
		.funeral = 0,
	};
	is_init = 1;
	return (&this);
}

void	free_rsc_arr(t_resource *rsc)
{
	int	i;

	i = -1;
	while (++i < rsc->n_philos)
	{
		pthread_mutex_destroy(rsc->forks[i]);
		free(rsc->philosophers[i]);
		free(rsc->forks[i]);
		free(rsc->philos[i]);
	}
	return ;
}

void	free_resource(void)
{
	t_resource	*rsc;
	int			i;

	rsc = single_rsc();
	free_rsc_arr(rsc);
	i = -1;
	while (++i < 5)
		pthread_mutex_destroy(rsc->printlock[i]);
	free(rsc->philos);
	free(rsc->philosophers);
	free(rsc->forks);
	free(rsc->time_table);
	i = -1;
	while (++i < 5)
		free(rsc->printlock[i]);
	return ;
}
