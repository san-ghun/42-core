/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:07:52 by sanghupa          #+#    #+#             */
/*   Updated: 2023/07/27 13:40:14 by sanghupa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

// Limit Loop: use addition to while condition
# define MAX_ITER	5000

// Prevent Heap mem leak: use addition to char or array
# define DATA_SIZE	3072

typedef struct s_resource
{
	size_t			n_philos;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_jam;
	size_t			n_eat_opt;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*printlock;
}					t_resource;

typedef struct s_philo
{
	size_t			id;
	size_t			n_ate;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}					t_philo;

/* philo.c */

/* philo_util.c */

#endif
