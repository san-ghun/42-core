/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:43 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/20 20:59:24 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*new_philo(size_t id)
{
	t_philo	*this;

	this = (t_philo *)malloc(sizeof(t_philo));
	this->id = id;
	this->pid = 0;
	this->n_ate = 0;
	this->status = 1;
	return (this);
}

void	init_philos(t_resource *rsc, int n_philo)
{
	int				i;

	i = -1;
	while (++i < n_philo)
		rsc->philos[i] = new_philo(i);
	return ;
}

t_resource	*init_resource(
			int n_philo,
			int t_die,
			int t_eat,
			int t_jam)
{
	t_resource		*rsc;

	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PLOCK);
	sem_unlink(SEM_ELOCK);
	sem_unlink(SEM_DLOCK);
	rsc = single_rsc();
	rsc->n_philos = n_philo;
	rsc->time_die = (long long)t_die;
	rsc->time_eat = (long long)t_eat;
	rsc->time_jam = (long long)t_jam;
	rsc->philos = malloc(sizeof(t_philo *) * n_philo);
	rsc->forks = sem_open(SEM_FORKS, O_CREAT, 0700, n_philo);
	rsc->printlock = sem_open(SEM_PLOCK, O_CREAT, 0700, 1);
	rsc->eatlock = sem_open(SEM_ELOCK, O_CREAT, 0700, 0);
	rsc->deadlock = sem_open(SEM_DLOCK, O_CREAT, 0700, 0);
	init_philos(rsc, n_philo);
	return (rsc);
}
