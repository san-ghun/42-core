/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:46 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/06 16:21:28 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	eat(t_philo *philo)
{
	if (single_rsc()->funeral)
		return (1);
	pthread_mutex_lock(philo->left);
	if (single_rsc()->funeral)
	{
		pthread_mutex_unlock(philo->left);
		return (1);
	}
	print_status(philo, 0);
	pthread_mutex_lock(philo->right);
	if (single_rsc()->funeral)
	{
		pthread_mutex_unlock(philo->right);
		return (1);
	}
	print_status(philo, 0);
	print_status(philo, 1);
	philo->t_last_meal = get_time_ms();
	usleep(single_rsc()->time_eat * 1000);
	philo->t_last_meal = get_time_ms();
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
	if (single_rsc()->funeral)
		return (1);
	return (0);
}

int	jam(t_philo *philo)
{
	if (single_rsc()->funeral)
		return (1);
	print_status(philo, 2);
	usleep(single_rsc()->time_jam * 1000);
	return (0);
}

int	think(t_philo *philo)
{
	if (single_rsc()->funeral)
		return (1);
	print_status(philo, 3);
	return (0);
}

int	die(t_philo *philo)
{
	if (single_rsc()->funeral)
		return (1);
	print_status(philo, 4);
	philo->status = 0;
	single_rsc()->funeral = 1;
	return (1);
}
