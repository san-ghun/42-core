/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:46 by sanghupa          #+#    #+#             */
/*   Updated: 2023/11/04 18:13:38 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*check_status(t_philo *philo)
{
	t_resource	*rsc;

	rsc = single_rsc();
	while (rsc->funeral != 1)
	{
		sem_wait(rsc->printlock);
		if (rsc->time_die + philo->t_last_meal < get_time_ms())
		{
			sem_post(rsc->printlock);
			print_dead(philo, rsc);
			break ;
		}
		sem_post(rsc->printlock);
		usleep(100);
	}
	return (NULL);
}

void	eat(t_philo *philo, t_resource *rsc)
{
	long long	target_time;

	sem_wait(rsc->forks);
	print_status(philo, rsc, "has taken a fork");
	sem_wait(rsc->forks);
	print_status(philo, rsc, "has taken a fork");
	sem_wait(rsc->printlock);
	philo->t_last_meal = get_time_ms();
	sem_post(rsc->printlock);
	print_status(philo, rsc, "is eating");
	target_time = rsc->time_eat + philo->t_last_meal;
	while (target_time > get_time_ms())
		usleep(100);
	sem_post(rsc->forks);
	sem_post(rsc->forks);
	philo->n_ate++;
	return ;
}

void	jam(t_philo *philo, t_resource *rsc)
{
	long long	target_time;

	target_time = rsc->time_jam + get_time_ms();
	print_status(philo, rsc, "is sleeping");
	while (target_time > get_time_ms())
		usleep(100);
	return ;
}

void	think(t_philo *philo, t_resource *rsc)
{
	print_status(philo, rsc, "is thinking");
	return ;
}
