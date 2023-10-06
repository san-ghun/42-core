/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:46 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/06 11:02:02 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	print_status(philo, 3);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(philo->left);
	print_status(philo, 0);
	pthread_mutex_lock(philo->right);
	print_status(philo, 0);
	print_status(philo, 1);
	usleep(resource_singleton()->time_eat * 1000);
	pthread_mutex_unlock(philo->left);
	pthread_mutex_unlock(philo->right);
}

void	jam(t_philo *philo)
{
	print_status(philo, 2);
	usleep(resource_singleton()->time_jam * 1000);
}

void	die(t_philo *philo)
{
	print_status(philo, 4);
}
