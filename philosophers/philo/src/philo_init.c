/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:43 by sanghupa          #+#    #+#             */
/*   Updated: 2023/11/09 14:46:40 by sanghupa         ###   ########.fr       */
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
	this->n_ate = 0;
	this->status = 1;
	this->left = left;
	this->right = right;
	return (this);
}

void	init_time_table(t_resource *rsc, int n_philo)
{
	int	i;
	int	ph_id;

	i = -1;
	ph_id = 0;
	while (ph_id < n_philo - 1)
	{
		rsc->time_table[++i] = ph_id;
		ph_id += 2;
	}
	rsc->time_table[++i] = n_philo - 1;
	ph_id = 1;
	while (ph_id < n_philo - 1)
	{
		rsc->time_table[++i] = ph_id;
		ph_id += 2;
	}
	return ;
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
		pthread_mutex_init(rsc->forks[i], NULL);
	}
	i = -1;
	while (++i < n_philo)
	{
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
	t_resource	*rsc;

	rsc = single_rsc();
	rsc->n_philos = n_philo;
	rsc->time_die = (long long)t_die;
	rsc->time_eat = (long long)t_eat;
	rsc->time_jam = (long long)t_jam;
	rsc->time_table = malloc(sizeof(int) * n_philo);
	rsc->philos = malloc(sizeof(t_philo *) * n_philo);
	rsc->philosophers = malloc(sizeof(pthread_t *) * n_philo);
	rsc->forks = malloc(sizeof(pthread_mutex_t *) * n_philo);
	init_time_table(rsc, n_philo);
	rsc->printlock = malloc(sizeof(pthread_mutex_t) * 1);
	init_thread_mutex(rsc, n_philo);
	rsc->next = &(rsc->time_table[0]);
	return (rsc);
}

void	init_table(t_resource *rsc)
{
	int			i;
	long long	time;

	i = -1;
	time = get_time_ms();
	while (++i < rsc->n_philos)
	{
		rsc->philos[i]->t_launch = time;
		rsc->philos[i]->t_last_meal = rsc->philos[i]->t_launch;
		pthread_create(rsc->philosophers[i], NULL, 
			(void *)philosopher, rsc->philos[i]);
	}
	return ;
}
