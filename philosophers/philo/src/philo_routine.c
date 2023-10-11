/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:46 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/11 23:25:46 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_next(t_resource *rsc)
{
	static int	i;

	pthread_mutex_lock(rsc->printlock[1]);
	rsc->next = &(rsc->time_table[++i]);
	if (i >= rsc->n_philos - 1)
		i = -1;
	pthread_mutex_unlock(rsc->printlock[1]);
}

void	eat(t_philo *philo, t_resource *rsc)
{
	long long	target_time;

	pthread_mutex_lock(philo->left);
	print_status(philo, rsc, "has taken a fork", 0);
	pthread_mutex_lock(philo->right);
	print_status(philo, rsc, "has taken a fork", 0);
	update_next(rsc);
	philo->t_last_meal = get_time_ms() + 3;
	print_status(philo, rsc, "is eating", 0);
	target_time = rsc->time_eat + philo->t_last_meal - 3;
	while (target_time > get_time_ms())
		usleep(100);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	philo->n_ate++;
	return ;
}

void	jam(t_philo *philo, t_resource *rsc)
{
	long long	target_time;

	target_time = rsc->time_jam + get_time_ms() - 1;
	print_status(philo, rsc, "is sleeping", 0);
	while (target_time > get_time_ms())
		usleep(100);
	return ;
}

void	think(t_philo *philo, t_resource *rsc)
{
	print_status(philo, rsc, "is thinking", 0);
	return ;
}
