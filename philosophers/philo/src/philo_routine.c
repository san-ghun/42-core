/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:46 by sanghupa          #+#    #+#             */
/*   Updated: 2023/11/09 14:49:11 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	update_next(t_resource *rsc)
{
	static int	i;

	pthread_mutex_lock(rsc->printlock);
	rsc->next = &(rsc->time_table[++i]);
	if (i >= rsc->n_philos - 1)
		i = -1;
	pthread_mutex_unlock(rsc->printlock);
}

void	eat(t_philo *philo, t_resource *rsc)
{
	long long	target_time;

	pthread_mutex_lock(philo->left);
	print_status(philo, rsc, "has taken a fork");
	pthread_mutex_lock(philo->right);
	print_status(philo, rsc, "has taken a fork");
	update_next(rsc);
	// philo->t_last_meal = get_time_ms() + 3;
	pthread_mutex_lock(rsc->printlock);
	philo->t_last_meal = get_time_ms();
	pthread_mutex_unlock(rsc->printlock);
	print_status(philo, rsc, "is eating");
	// target_time = rsc->time_eat + philo->t_last_meal - 3;
	target_time = rsc->time_eat + philo->t_last_meal;
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

	// target_time = rsc->time_jam + get_time_ms() - 1;
	target_time = rsc->time_jam + get_time_ms();
	print_status(philo, rsc, "is sleeping");
	while (target_time > get_time_ms())
		usleep(100);
	return ;
}

int	check_meal(t_philo *philo, t_resource *rsc)
{
	if (philo->n_ate == rsc->n_eat_opt)
	{
		pthread_mutex_lock(rsc->printlock);
		rsc->n_eat_cnt += 1;
		pthread_mutex_unlock(rsc->printlock);
		return (1);
	}
	return (0);
}

void	routine(t_philo *philo, t_resource *rsc)
{
	while (1)
	{
		pthread_mutex_lock(rsc->printlock);
		if (rsc->funeral == 1)
		{
			pthread_mutex_unlock(rsc->printlock);
			break ;
		}
		if (philo->id != *(rsc->next))
		{
			pthread_mutex_unlock(rsc->printlock);
			usleep(10);
			continue ;
		}
		pthread_mutex_unlock(rsc->printlock);
		eat(philo, rsc);
		if (check_meal(philo, rsc) == 1)
			break ;
		jam(philo, rsc);
		print_status(philo, rsc, "is thinking");
	}
	return ;
}
