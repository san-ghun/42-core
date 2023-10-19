/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_resource.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:48 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/19 15:21:49 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

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
		// .philosophers = NULL,
		.forks = NULL,
		.printlock = NULL,
		.queuelock = NULL,
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
		// free(rsc->philosophers[i]);
		free(rsc->philos[i]);
	}
	sem_close(rsc->forks);
	sem_unlink(SEM_FORKS);
	// free(rsc->forks);
	return ;
}

void	free_resource(void)
{
	t_resource	*rsc;
	int			i;

	rsc = single_rsc();
	free_rsc_arr(rsc);
	sem_close(rsc->printlock);
	sem_unlink(SEM_PLOCK);
	sem_close(rsc->queuelock);
	sem_unlink(SEM_QLOCK);
	free(rsc->philos);
	// free(rsc->philosophers);
	free(rsc->time_table);
	return ;
}
