/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 13:46:46 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/05 15:07:56 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// TODO: implement
void	print(pthread_mutex_t *printlock, size_t id, char *str)
{
	pthread_mutex_lock(printlock);
	printf("%s\n", str);
	pthread_mutex_unlock(printlock);
}

// TODO: implement
void	jam(size_t id)
{
	// sleep_for(get_sleep);
}

// TODO: implement
void	think(size_t id)
{
	printf("%zu: starts thinking...\n", id);
	// sleep_for(get_think);
	printf("%zu: done thinking.\n", id);
}

// TODO: implement
void	eat(size_t id, \
			pthread_mutex_t *left, \
			pthread_mutex_t *right)
{
	pthread_mutex_lock(left);
	pthread_mutex_lock(right);
	printf("%zu: starts eating om nom nom ...\n", id);
	// sleep_for(get_eat);
	printf("%zu: done eating.\n", id);
	pthread_mutex_unlock(left);
	pthread_mutex_unlock(right);
}
