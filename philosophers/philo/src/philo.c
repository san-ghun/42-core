/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:07:53 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/27 13:53:22 by sanghupa         ###   ########.fr       */
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

	return (this);
}

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
	// sleep_for(get_think);
}

// TODO: implement
void	eat(size_t id, \
				pthread_mutex_t *left, \
				pthread_mutex_t *right)
{
	pthread_mutex_lock(left);
	pthread_mutex_lock(right);
	// sleep_for(get_eat);
	pthread_mutex_unlock(left);
	pthread_mutex_unlock(right);
}

// TODO: implement
void	*philosopher(size_t id, \
					pthread_mutex_t *left, \
					pthread_mutex_t *right)
{
	think(id);
	eat(id, left, right);
	jam(id);
	return (0);
}

int	main(int argc, char *argv[])
{
	int				i;
	t_philo			*philos[5];
	pthread_t		*philosophers[5];
	pthread_mutex_t	*forks[5];
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
	pthread_mutex_t	print;

	(void)argc;
	(void)argv;
	i = 0;
	pthread_mutex_init(&print, NULL);
	while (i < 5)
	{
		pthread_mutex_init(forks[i], NULL);
		pthread_mutex_init(forks[(i + 1) % 5], NULL);
		left = forks[i];
		right = forks[(i + 1) % 5];
		philos[i] = new_philo(i, left, right);
		pthread_create(philosophers[i], NULL, philosopher, philos[i]);
		i++;
	}
	i = 0;
	while (i < 5)
		pthread_join(*philosophers[i++], NULL);
	return (0);
}
