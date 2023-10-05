/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:43 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/05 17:45:13 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_philo	*new_philo(size_t id, \
					pthread_mutex_t *left, \
					pthread_mutex_t *right)
{
	t_philo	*this;

	this = (t_philo *)malloc(sizeof(t_philo));
	this->id = id;
	this->left = left;
	this->right = right;
	this->n_ate = 0;
	return (this);
}

t_resource	*init_resource(
			int n_philo,
			int t_die,
			int t_eat,
			int t_sleep)
{
	int				i;
	t_resource		*rsc;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;

	rsc = resource_singleton();
	rsc->time_die = t_die;
	rsc->time_eat = t_eat;
	rsc->time_jam = t_sleep;
	rsc->philos = malloc(sizeof(t_philo *) * n_philo);
	rsc->philosophers = malloc(sizeof(pthread_t *) * n_philo);
	rsc->forks = malloc(sizeof(pthread_mutex_t *) * n_philo);
	rsc->printlock = malloc(sizeof(pthread_mutex_t) * 1);
	pthread_mutex_init(rsc->printlock, NULL);
	i = -1;
	while (++i < n_philo)
	{
		rsc->philosophers[i] = malloc(sizeof(pthread_t) * 1);
		rsc->forks[i] = malloc(sizeof(pthread_mutex_t) * 1);
	}
	i = -1;
	while (++i < n_philo)
	{
		pthread_mutex_init(rsc->forks[i], NULL);
		pthread_mutex_init(rsc->forks[(i + 1) % n_philo], NULL);
		left = rsc->forks[i];
		right = rsc->forks[(i + 1) % n_philo];
		rsc->philos[i] = new_philo(i, left, right);
	}
	return (rsc);
}
