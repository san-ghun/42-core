/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:43 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/06 00:04:40 by sanghupa         ###   ########.fr       */
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
	this->status = 1;
	this->n_ate = 0;
	this->t_launch = get_time_ms();
	this->t_last_meal = 0;
	this->left = left;
	this->right = right;
	return (this);
}

void	init_thread_mutex(t_resource *rsc, int n_philo)
{
	int				i;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;

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

	rsc = resource_singleton();
	rsc->n_philos = n_philo;
	rsc->time_die = t_die;
	rsc->time_eat = t_eat;
	rsc->time_jam = t_jam;
	rsc->philos = malloc(sizeof(t_philo *) * n_philo);
	rsc->philosophers = malloc(sizeof(pthread_t *) * n_philo);
	rsc->forks = malloc(sizeof(pthread_mutex_t *) * n_philo);
	rsc->printlock = malloc(sizeof(pthread_mutex_t) * 1);
	init_thread_mutex(rsc, n_philo);
	return (rsc);
}
