/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sanghupa <sanghupa@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:07:52 by sanghupa          #+#    #+#             */
/*   Updated: 2023/10/06 00:29:20 by sanghupa         ###   ########.fr       */
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

typedef struct s_philo
{
	size_t			id;
	uint8_t			status;
	size_t			n_ate;
	long long		t_launch;
	long long		t_last_meal;
	pthread_mutex_t	*left;
	pthread_mutex_t	*right;
}					t_philo;

typedef struct s_resource
{
	size_t			n_philos;
	size_t			time_die;
	size_t			time_eat;
	size_t			time_jam;
	size_t			n_eat_opt;
	t_philo			**philos;
	pthread_t		**philosophers;
	pthread_mutex_t	**forks;
	pthread_mutex_t	*printlock;
}					t_resource;

/* philo.c */

/* philo_resource.c */
t_resource	*resource_singleton(void);
void		free_resource(void);

/* philo_init.c */
t_resource	*init_resource(int n_philo, int t_die, int t_eat, int t_jam);

/* philo_routine.c */
void		jam(size_t id);
void		think(size_t id);
void		eat(size_t id, pthread_mutex_t *left, pthread_mutex_t *right);
void		die(size_t id);

/* philo_util.c */
int			check_args(int argc, char *argv[]);
int			ft_atoi(const char *str);
long long	get_time_ms(void);
void		print_status(pthread_mutex_t *printlock, size_t id, char *str);

#endif
