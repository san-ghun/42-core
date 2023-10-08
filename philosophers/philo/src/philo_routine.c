/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:46 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/08 00:17:40 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*imkant(long long the_time, t_philo *philo, int meal)
{
	long long	target_time;

	target_time = the_time + get_time_ms();
	while (get_time_ms() < target_time)
		usleep(50);
	return (0);
}

void	eat(t_philo *philo, t_resource *rsc)
{
	pthread_mutex_lock(philo->left);
	print_status(philo, rsc, "has taken a fork");
	pthread_mutex_lock(philo->right);
	print_status(philo, rsc, "has taken a fork");
	print_status(philo, rsc, "is eating");
	philo->t_last_meal = get_time_ms();
	imkant(rsc->time_eat, philo, 1);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	philo->n_ate++;
	return ;
}

void	jam(t_philo *philo, t_resource *rsc)
{
	print_status(philo, rsc, "is sleeping");
	imkant(rsc->time_jam, philo, 0);
	return ;
}

void	think(t_philo *philo, t_resource *rsc)
{
	(void)rsc;
	print_status(philo, rsc, "is thinking");
	usleep(500);
	return ;
}
