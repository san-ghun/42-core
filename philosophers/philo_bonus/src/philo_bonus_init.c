/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_init.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:43 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/19 15:49:09 by sanghupa         ###   ########.fr       */
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

void	init_time_table(t_resource *rsc, int n_philo)
{
	int	i;
	int	ph_id;

	i = -1;
	ph_id = 0;
	while (ph_id < n_philo)
	{
		rsc->time_table[++i] = ph_id;
		ph_id += 2;
	}
	ph_id = 1;
	while (ph_id < n_philo)
	{
		rsc->time_table[++i] = ph_id;
		ph_id += 2;
	}
	return ;
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
	int				i;
	t_resource		*rsc;

	sem_unlink(SEM_FORKS);
	sem_unlink(SEM_PLOCK);
	sem_unlink(SEM_QLOCK);
	rsc = single_rsc();
	rsc->n_philos = n_philo;
	rsc->time_die = (long long)t_die;
	rsc->time_eat = (long long)t_eat;
	rsc->time_jam = (long long)t_jam;
	rsc->time_table = malloc(sizeof(int) * n_philo);
	rsc->philos = malloc(sizeof(t_philo *) * n_philo);
	// rsc->philosophers = malloc(sizeof(pthread_t *) * n_philo);
	rsc->forks = sem_open(SEM_FORKS, O_CREAT, 0700, n_philo);
	init_time_table(rsc, n_philo);
	rsc->printlock = sem_open(SEM_PLOCK, O_CREAT, 0700, 1);
	rsc->queuelock = sem_open(SEM_QLOCK, O_CREAT, 0700, 1);
	init_philos(rsc, n_philo);
	rsc->next = &(rsc->time_table[0]);
	return (rsc);
}
